/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  intctrl_program.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "intctrl_interface.h"
#include "intctrl_private.h"
#include "intctrl_config.h"
#include "mcu_hw.h"
#include "bit_math.h"

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


/******************************************************************************
* \Syntax          : void INTCTRL_init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers
*                    - group, sup group priority
*                    - enable, disable                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Config_Ptr                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void INTCTRL_init(IntrCfg_ConfigTypes* Config_Ptr)
{
    uint8 i = 0;
    uint32 totalPriority = 0;

    /*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    APINT = 0x05FA0000 | (PRI_CONTROL<<8);
    
    for (i=0; i<NUM_OF_INTERRUPTS; i++)
    {

        IntCtrl_InterruptType interruptId = Config_Ptr[i].InterruptName;
        GroupPriLevel_Type groupLvl       = Config_Ptr[i].GroupLevel;
        SubGroupPriLevel_Type subGroupLvl = Config_Ptr[i].SubGroupLevel;
        uint8 interruptMode               = Config_Ptr[i].InterruptMode;

        /* Calculating the total priority for SCB or NVIC */
    #if  ( PRI_CONTROL == PRI_CONTROL_XXX )
        
        totalPriority = groupLvl;    
               
    #elif ( PRI_CONTROL == PRI_CONTROL_XXY )
        
        totalPriority = (groupLvl<<1 & 0x6) | (subGroupLvl & 0x1); 
        
    #elif ( PRI_CONTROL == PRI_CONTROL_XYY )
        
        totalPriority = (groupLvl<<2 & 0x4) | (subGroupLvl & 0x3);    
                
    #elif ( PRI_CONTROL == PRI_CONTROL_YYY )
        
        totalPriority = subGroupLvl; 
        
    #endif

       if (interruptId < 16)
       {
        /*
         * HANDLING SCB PRIORITY AND ENABLE/DISABLE
         */
        if ( interruptId == MEMORY_MANAGEMENT_FAULT )
        {
            SYSPRI1 = ( SYSPRI1 & 0xFFFFFF1F ) | ( totalPriority<<5);
            SYSHNDCTRL |= interruptMode<<16;

        }
        else if ( interruptId == BUS_FAULT )
        {
            SYSPRI1 = ( SYSPRI1 & 0xFFFF1FFF ) | ( totalPriority<<13);
            SYSHNDCTRL |= interruptMode<<17;
        }
        else if ( interruptId == USAGE_FAULT )
        {
            SYSPRI1 = ( SYSPRI1 & 0xFF1FFFFF ) | ( totalPriority<<21);
            SYSHNDCTRL |= interruptMode<<18;
        }
        else if ( interruptId == SV_CALL )
        {
            SYSPRI2 = ( SYSPRI2 & 0x1FFFFFFF ) | ( totalPriority<<29); 
        }
        else if ( interruptId == DEBUG_MONITOR )
        {
            SYSPRI3 = ( SYSPRI3 & 0xFFFFFF1F ) | ( totalPriority<<5);
        }
        else if ( interruptId == PEND_SV )
        {
            SYSPRI3 = ( SYSPRI3 & 0xFF1FFFFF ) | ( totalPriority<<21);
        }
        else if ( interruptId == SYS_TICK )
        {
            SYSPRI3 = ( SYSPRI3 & 0x1FFFFFFF ) | ( totalPriority<<29 );
            STCTRL |= interruptMode<<1; 
        } 
   
        }
        else if ( interruptId >= 16 || interruptId <= 154 )
        {
            uint32 bitNumber;
            uint32 newInterruptId = interruptId - 16;
            
            /*
             * HANDLING NVIC PRIORITY 
             * - get the first priority bit number of the three based on the interrrupt number
             * - insert the required priority in the required bits in the required register
             */
            bitNumber = ((newInterruptId % 4U) * 8U) + 5; 
            PRIx(newInterruptId) |= totalPriority<<bitNumber; 

            /*
             * HANDLING NVIC ENABLE/DISABLE 
             * - get the enable bit number based on the interrrupt number
             * - insert the required enable in the required bit in the required register
             */
            bitNumber = newInterruptId % 32U;
            if ( interruptMode == ENABLE )
            {
                SET_BIT(ENx(newInterruptId),bitNumber); 
            }
            else if ( interruptMode == DISABLE ) 
            {
                CLEAR_BIT(ENx(newInterruptId),bitNumber); 
            }   
        }
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/