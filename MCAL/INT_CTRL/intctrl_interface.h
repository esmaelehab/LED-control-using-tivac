/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  intctrl_interface.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_INTERFACE_H
#define INTCTRL_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define	PRI_CONTROL_XXX	 0x4
#define	PRI_CONTROL_XXY	 0x5
#define	PRI_CONTROL_XYY	 0x6
#define	PRI_CONTROL_YYY	 0x7

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum {
    GROUP_LEVEL0 = 0,
    GROUP_LEVEL1 = 1,
    GROUP_LEVEL2 = 2,
    GROUP_LEVEL3 = 3,
    GROUP_LEVEL4 = 4,
    GROUP_LEVEL5 = 5,
    GROUP_LEVEL6 = 6,
    GROUP_LEVEL7 = 7

}GroupPriLevel_Type;

typedef enum {
    SUB_GROUP_LEVEL0 = 0,
    SUB_GROUP_LEVEL1 = 1,
    SUB_GROUP_LEVEL2 = 2,
    SUB_GROUP_LEVEL3 = 3,
    SUB_GROUP_LEVEL4 = 4,
    SUB_GROUP_LEVEL5 = 5,
    SUB_GROUP_LEVEL6 = 6,
    SUB_GROUP_LEVEL7 = 7

}SubGroupPriLevel_Type;

typedef enum {
    RESET = 1,
    NON_MASKABLE_INTERRUPT = 2,
    HARD_FAULT = 3,
    MEMORY_MANAGEMENT_FAULT = 4,
    BUS_FAULT = 5,
    USAGE_FAULT = 6,
    SV_CALL = 11,
    DEBUG_MONITOR = 12,
    PEND_SV = 14,
    SYS_TICK = 15,
    GPIO_PORT_A = 16,
    GPIO_PORT_B = 17,
    GPIO_PORT_C = 18,
    GPIO_PORT_D = 19,
    GPIO_PORT_E = 20,
    TIMER0A_16_32_BIT = 35,
    GPIO_PORT_F = 46,
    TIMER0A_32_64_BIT = 110

}IntCtrl_InterruptType;


typedef struct {
    IntCtrl_InterruptType InterruptName;
    GroupPriLevel_Type  GroupLevel;
    SubGroupPriLevel_Type SubGroupLevel;
    uint8 InterruptMode;
    
}IntrCfg_ConfigTypes;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
void INTCTRL_init(IntrCfg_ConfigTypes* Config_Ptr);


#endif  /* INTCTRL_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: intctrl_interface.h
 *********************************************************************************************************************/