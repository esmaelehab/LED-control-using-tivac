/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_program.c
 *        \brief  source file for the port driver
 *
 *      \details  enable each channel given in each port with the required configurations
 *                channel type, attachment type, current value, interrrupt type
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "port_private.h"
#include "port_interface.h"
#include "port_config.h"
#include "mcu_hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/* global array to hold the addresses of each port */
static volatile uint32 g_portBaseAddr[MAX_NUM_OF_PORTS] = {
     PORT_A_BASE_ADDRESS, PORT_B_BASE_ADDRESS, PORT_C_BASE_ADDRESS, PORT_D_BASE_ADDRESS, PORT_E_BASE_ADDRESS, PORT_F_BASE_ADDRESS};

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


/**********************************************************************************
* \Syntax          : void PORT_init (void)      
* \Description     : Enable the required gpio pins with the given configuration                                   
*                    - pin mode ( Dio, Ain, other alterante functions )
*                    - pin direction ( input , output )
*                    - attachment type ( pullup, pulldown, opn drain )
*                    - current value ( 2mA, 4mA, 8mA )
*                    - interrupt status and type ( enable, disable )
*                      (rising edge, falling edge, low level, high level )  

* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Config_Ptr                    
* \Parameters (out): None                                                      
* \Return value:   : None                                  
**********************************************************************************/
void PORT_init (Port_CfgType* Config_Ptr)
{
    uint32 i;
    uint32 Addr;

    for (i=0; i<NUM_OF_ACTIVE_CH; i++)
    {
        Port_Type portId                     = Config_Ptr[i].Pin_ID / MAX_NUM_OF_CH;
        Port_PinType chId                    = Config_Ptr[i].Pin_ID % MAX_NUM_OF_CH;
        Port_PinModeType modeId              = Config_Ptr[i].Mode;
        Port_PinInternalAttachType attachId  = Config_Ptr[i].Attach;
        Port_PinOutputCurrentType currentId  = Config_Ptr[i].Current;
        Port_InterruptType interrruptId      = Config_Ptr[i].Interrupt;
        
        Addr = g_portBaseAddr[portId];

        GPIODIR(Addr) |= (Config_Ptr[i].Direction<<chId);
        //GPIOLOCK(Addr) = GPIO_UNLOCK_VALUE;
		//GPIOCR(Addr) = 0x1;

        /* if pin mode is dio pin 
        *  - disable the altrenate funtion by clearing the required bit in GPIOAFSEL register
        *  - enable the pin digital function in GPIODEN register
        *  - disable the pin analog function in GPIOAMSEL register
        */  
        if ( modeId == PIN_X_MODE_DIO )
        {
            CLEAR_BIT(GPIOAFSEL(Addr),chId);
            SET_BIT(GPIODEN(Addr),chId);
            CLEAR_BIT(GPIOAMSEL(Addr),chId);
        }

        /* if pin mode is adc pin 
        *  - enable the altrenate funtion by setting the required bit in GPIOAFSEL register
        *  - disable the pin digital function in GPIODEN register
        *  - enable the pin analog function in GPIOAMSEL register
        */ 
        else if (modeId == PIN_X_MODE_AIN)
        {
           SET_BIT(GPIOAFSEL(Addr),chId);
           CLEAR_BIT(GPIODEN(Addr),chId);
           SET_BIT(GPIOAMSEL(Addr),chId);
        }
        
        /* - enable the altrenate funtion by setting the required bit in GPIOAFSEL register
        *  - enable the pin digital fuction in GPIODEN register
        *  - set the alternate function in GPIOPCTL register
        */  
        else
        {
            SET_BIT(GPIOAFSEL(Addr),chId);
            SET_BIT(GPIODEN(Addr),chId);
            GPIOPCTL(Addr) |= (modeId<<(4*chId)); 
        }

        /* choose the required attach configuration */ 
        switch (attachId)
        {
            case PULL_UP: SET_BIT(GPIOPUR(Addr),chId);
                break;

            case PULL_DOWN: SET_BIT(GPIOPDR(Addr),chId);
                break;
   
            case OPEN_DRAIN: SET_BIT(GPIOODR(Addr),chId);
                break;

            default:
                break;
        }    
        
        /* choose the required cuurent value for each pin */
        switch (currentId)
        {
            case CURRENT_2mA: SET_BIT(GPIODR2R(Addr),chId);
                break;

            case CURRENT_4mA: SET_BIT(GPIODR4R(Addr),chId);
                break;   
        
            case CURRENT_8mA: SET_BIT(GPIODR8R(Addr),chId);
                break;
        
            default:
                break;
        }
        
        /* choose the interrrupt state for each pin */
        switch(interrruptId)
        {
            case INTERRUPT_DISABLE: CLEAR_BIT(GPIOIM(Addr),chId);
                break;

            case INTERRUPT_RISING_EDGE:
                CLEAR_BIT(GPIOIM(Addr),chId);
                CLEAR_BIT(GPIOIS(Addr),chId);
                CLEAR_BIT(GPIOIBE(Addr),chId);
                SET_BIT(GPIOIEV(Addr),chId);
                SET_BIT(GPIOIM(Addr),chId);
                break;

            case INTERRUPT_FALLING_EDGE:
                CLEAR_BIT(GPIOIM(Addr),chId);
                CLEAR_BIT(GPIOIS(Addr),chId);
                CLEAR_BIT(GPIOIBE(Addr),chId);
                CLEAR_BIT(GPIOIEV(Addr),chId);
                SET_BIT(GPIOIM(Addr),chId); 
                break;

            case INTERRUPT_BOTH_EDGES:
                CLEAR_BIT(GPIOIM(Addr),chId);
                CLEAR_BIT(GPIOIS(Addr),chId);
                SET_BIT(GPIOIBE(Addr),chId);
                SET_BIT(GPIOIM(Addr),chId); 
                break;

            case INTERRUPT_HIGH_LEVEL:
                CLEAR_BIT(GPIOIM(Addr),chId);
                SET_BIT(GPIOIS(Addr),chId);
                SET_BIT(GPIOIEV(Addr),chId);
                SET_BIT(GPIOIM(Addr),chId);
                break;

            case INTERRUPT_LOW_LEVEL:
                CLEAR_BIT(GPIOIM(Addr),chId);
                SET_BIT(GPIOIS(Addr),chId);
                CLEAR_BIT(GPIOIEV(Addr),chId);
                SET_BIT(GPIOIM(Addr),chId);
                break; 

            default:
                break;                  
        }
    }  
}

/**********************************************************************************************************************
 *  END OF FILE: Port_program.c
 *********************************************************************************************************************/