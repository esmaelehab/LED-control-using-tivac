/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  sysctrl_program.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "mcu_hw.h"
#include "Std_Types.h"
#include "bit_math.h" 
#include "sysctrl_interface.h"
#include "sysctrl_config.h"
#include "sysctrl_private.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/*******************************************************************************
* \Syntax          : void SYSCTRL_init (void)        
* \Description     : set the system clock cgiven configuration
*                    - pll enable or disable
*                    - clock source ( main oscillator , internal oscillator )
                     - system clock frequency ( by using divisor value )                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                        
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void SYSCTRL_init (SysCtrl_CfgTypes* Config_Ptr)
{
    uint8 clkSource   = Config_Ptr->ClockSource;
    uint8 crystalFreq = Config_Ptr->CrystalFreq;
    uint8 divisor     = Config_Ptr->SysFreqDiv;

    SET_BIT(RCC2, USERCC2);

    /* disable PLL while initialization by clearing BYBASS bit */
    SET_BIT(RCC,BYBASS);
    SET_BIT(RCC2,BYBASS2);
    
    CLEAR_BIT(RCC,USESYSDIV);

    SET_BIT(RCC,PWRDN);
    SET_BIT(RCC2,PWRDN2);

    
    if ( PLL_ENABLED == FALSE )
    {
        if ( clkSource == MOSC )
        {
            /* - enable main oscillator 
            *  - choose main oscillator in OSCSRC bit field 
            *  - choose main oscilattor crystal frequency in XTAL field
            */ 
            CLEAR_BIT(RCC,MOSCDIS);
            RCC  = ( RCC  & 0xFFFFFFCF )  | ( clkSource << 4 );
            RCC2 = ( RCC2 & 0xFFFFFF8F )  | ( clkSource << 4 );
            RCC  = ( RCC  & 0xFFFFF83F )  | ( crystalFreq << 6 ); 
        }
        else if ( clkSource == PIOSC )
        {
            /* choose precision internal oscillator */ 
            RCC  = ( RCC  & 0xFFFFFFCF ) | ( clkSource << 4);
            RCC2 = ( RCC2 & 0xFFFFFF8F ) | ( clkSource << 4);
        }
        else if ( clkSource == PIOSC_4 )
        {
            /* choose precision internal oscillator */ 
            RCC  = ( RCC  & 0xFFFFFFCF ) | ( clkSource << 4);
            RCC2 = ( RCC2 & 0xFFFFFF8F ) | ( clkSource << 4);
        }
        /* - enable using system dividor by setting USERSYSDIV bit 
        *  - set the system clock frequency 
        */
        SET_BIT(RCC,USESYSDIV);
        RCC2 = ( RCC2 & 0xE07FFFFF ) | ( (divisor-1) << 23 );
    }
    else if ( PLL_ENABLED == FALSE )
    {
        if ( clkSource == MOSC )
        {
            /* - enable main oscillator 
            *  - choose main oscillator in OSCSRC bit field 
            *  - choose main oscilattor crystal frequency in XTAL field
            */ 
            CLEAR_BIT(RCC,MOSCDIS);
            RCC  = ( RCC  & 0xFFFFFFCF )  | ( clkSource << 4 );
            RCC2 = ( RCC2 & 0xFFFFFF8F )  | ( clkSource << 4 );
            RCC  = ( RCC  & 0xFFFFF83F )  | ( crystalFreq << 6 ); 
        }
        else if ( clkSource == PIOSC )
        {
            /* choose precision internal oscillator */ 
            RCC  = ( RCC  & 0xFFFFFFCF ) | ( clkSource << 4);
            RCC2 = ( RCC2 & 0xFFFFFF8F ) | ( clkSource << 4);
        }
        /* - enable PLL by clearing PWRDN bit 
        *  - enable using system dividor by setting USERSYSDIV bit 
        *  - set 400 mhz from pll and calculate SYSDIV2 value 
        *  - set the system clock frequency 
        *  - wait until PLL is stable
        *  - set the PLL as system clock source by clearing BYBASS bit
        */
        if ( divisor > 4 )
        {
            CLEAR_BIT(RCC,PWRDN);
            CLEAR_BIT(RCC2,PWRDN2);
            SET_BIT(RCC,USESYSDIV);
            SET_BIT(RCC2,DIV400);

            if ( divisor/2 != 0 )
            {
                CLEAR_BIT(RCC2, SYSDIV2LSB);
                RCC2 = (RCC2 & 0xE07FFFFF ) | ((divisor/2)<<23);
            }
            else if ( divisor/2 == 0 )
            {
                SET_BIT(RCC2, SYSDIV2LSB);
                RCC2 = (RCC2 & 0xE07FFFFF ) | (((divisor/2) - 1)<<23);
            }

            while(BIT_IS_CLEAR(RIS,PLLLRIS));
            CLEAR_BIT(RCC,BYBASS);
            CLEAR_BIT(RCC2,BYBASS2);
        }
    }

 
 
}

/******************************************************************************
* \Syntax          : void SYSCTRL_periphralEnableClock (void)        
* \Description     : Set clock for each periphral                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Config_Ptr Configuration pointer to struct                      
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/

void SYSCTRL_periphralEnableClock (SysCtrl_PheriphralCfgTypes* Config_Ptr)
{
    uint16 periphral;  
    uint8 modulePinNum;
    uint16 i;

    for (i=0; i<NUMBER_OF_PERIPH; i++)
    {
        periphral = Config_Ptr[i].Peripheral;
        modulePinNum = Config_Ptr[i].PeripheralModule;
       
        SET_BIT(RCGC(periphral), modulePinNum);
    }   
}


/**********************************************************************************************************************
 *  END OF FILE: sysctrl_program.c
 *********************************************************************************************************************/