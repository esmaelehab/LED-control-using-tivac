/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  sysctrl_interface.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYSCTRL_INTERFACE_H
#define SYSCTRL_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define MOSC         (0x0)
#define PIOSC        (0x1)
#define PIOSC_4      (0x2)
#define LFIOSC       (0x3)
#define HIBERNATION  (0x7)
  

#define NO_EXTERNAL_CRYSTAL             (0x00)
#define CRYSTAL_FREQ_4MHZ               (0x06)            
#define CRYSTAL_FREQ_4_096MHZ           (0x07)
#define CRYSTAL_FREQ_4_9152MHZ          (0x08)
#define CRYSTAL_FREQ_5MHZ               (0x09)
#define CRYSTAL_FREQ_5_12MHZ            (0x0A)
#define CRYSTAL_FREQ_6MHZ               (0x0B)
#define CRYSTAL_FREQ_6_144MHZ           (0x0C)
#define CRYSTAL_FREQ_7_3728MHZ          (0x0D)
#define CRYSTAL_FREQ_8MHZ               (0x0E)
#define CRYSTAL_FREQ_8_192MHZ           (0x0F)
#define CRYSTAL_FREQ_10MHZ              (0x10)
#define CRYSTAL_FREQ_12MHZ              (0x11)
#define CRYSTAL_FREQ_12_288MHZ          (0x12)
#define CRYSTAL_FREQ_13_56MHZ           (0x13)
#define CRYSTAL_FREQ_14_31818MHZ        (0x14)
#define CRYSTAL_FREQ_16MHZ              (0x15)
#define CRYSTAL_FREQ_16_384MHZ          (0x16)
#define CRYSTAL_FREQ_18MHZ              (0x17)
#define CRYSTAL_FREQ_20MHZ              (0x18)
#define CRYSTAL_FREQ_24MHZ              (0x19)
#define CRYSTAL_FREQ_25MHZ              (0x1A)

#define GPIO_PERIPH_CLOCK_GATE          0x608
#define UART_PERIPH_CLOCK_GATE          0x618
#define TIMER_16_32_PERIPH_CLOCK_GATE   0x604
#define TIMER_32_64_PERIPH_CLOCK_GATE   0x65C


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum 
{
    SYS_CLK_FREQ_DIV_1 = 1,
    SYS_CLK_FREQ_DIV_2,
    SYS_CLK_FREQ_DIV_3,
    SYS_CLK_FREQ_DIV_4,
    SYS_CLK_FREQ_DIV_5,
    SYS_CLK_FREQ_DIV_6,
    SYS_CLK_FREQ_DIV_7,
    SYS_CLK_FREQ_DIV_8,
    SYS_CLK_FREQ_DIV_9,
    SYS_CLK_FREQ_DIV_10,
    SYS_CLK_FREQ_DIV_11,
    SYS_CLK_FREQ_DIV_12,
    SYS_CLK_FREQ_DIV_13,
    SYS_CLK_FREQ_DIV_14,
    SYS_CLK_FREQ_DIV_15,
    SYS_CLK_FREQ_DIV_16,
    SYS_CLK_FREQ_DIV_17,
    SYS_CLK_FREQ_DIV_18,
    SYS_CLK_FREQ_DIV_19,
    SYS_CLK_FREQ_DIV_20,
    SYS_CLK_FREQ_DIV_21,
    SYS_CLK_FREQ_DIV_22,
    SYS_CLK_FREQ_DIV_23,
    SYS_CLK_FREQ_DIV_24,
    SYS_CLK_FREQ_DIV_25,
    SYS_CLK_FREQ_DIV_26,
    SYS_CLK_FREQ_DIV_27,
    SYS_CLK_FREQ_DIV_28,
    SYS_CLK_FREQ_DIV_29,
    SYS_CLK_FREQ_DIV_30,
    SYS_CLK_FREQ_DIV_31,
    SYS_CLK_FREQ_DIV_32,
    SYS_CLK_FREQ_DIV_33,
    SYS_CLK_FREQ_DIV_34,
    SYS_CLK_FREQ_DIV_35,
    SYS_CLK_FREQ_DIV_36,
    SYS_CLK_FREQ_DIV_37,
    SYS_CLK_FREQ_DIV_38,
    SYS_CLK_FREQ_DIV_39,
    SYS_CLK_FREQ_DIV_40,
    SYS_CLK_FREQ_DIV_41,
    SYS_CLK_FREQ_DIV_42,
    SYS_CLK_FREQ_DIV_43,
    SYS_CLK_FREQ_DIV_44,
    SYS_CLK_FREQ_DIV_45,
    SYS_CLK_FREQ_DIV_46,
    SYS_CLK_FREQ_DIV_47,
    SYS_CLK_FREQ_DIV_48,
    SYS_CLK_FREQ_DIV_49,
    SYS_CLK_FREQ_DIV_50,
    SYS_CLK_FREQ_DIV_51,
    SYS_CLK_FREQ_DIV_52,
    SYS_CLK_FREQ_DIV_53,
    SYS_CLK_FREQ_DIV_54,
    SYS_CLK_FREQ_DIV_55,
    SYS_CLK_FREQ_DIV_56,
    SYS_CLK_FREQ_DIV_57,
    SYS_CLK_FREQ_DIV_58,
    SYS_CLK_FREQ_DIV_59,
    SYS_CLK_FREQ_DIV_60,
    SYS_CLK_FREQ_DIV_61,
    SYS_CLK_FREQ_DIV_62,
    SYS_CLK_FREQ_DIV_63,
    SYS_CLK_FREQ_DIV_64,
    SYS_CLK_FREQ_DIV_65,
    SYS_CLK_FREQ_DIV_66,
    SYS_CLK_FREQ_DIV_67,
    SYS_CLK_FREQ_DIV_68,
    SYS_CLK_FREQ_DIV_69,
    SYS_CLK_FREQ_DIV_70,
    SYS_CLK_FREQ_DIV_71,
    SYS_CLK_FREQ_DIV_72,
    SYS_CLK_FREQ_DIV_73,
    SYS_CLK_FREQ_DIV_74,
    SYS_CLK_FREQ_DIV_75,
    SYS_CLK_FREQ_DIV_76,
    SYS_CLK_FREQ_DIV_77,
    SYS_CLK_FREQ_DIV_78,
    SYS_CLK_FREQ_DIV_79,
    SYS_CLK_FREQ_DIV_80,
    SYS_CLK_FREQ_DIV_81,
    SYS_CLK_FREQ_DIV_82,
    SYS_CLK_FREQ_DIV_83,
    SYS_CLK_FREQ_DIV_84,
    SYS_CLK_FREQ_DIV_85,
    SYS_CLK_FREQ_DIV_86,
    SYS_CLK_FREQ_DIV_87,
    SYS_CLK_FREQ_DIV_88,
    SYS_CLK_FREQ_DIV_89,
    SYS_CLK_FREQ_DIV_90,
    SYS_CLK_FREQ_DIV_91,
    SYS_CLK_FREQ_DIV_92,
    SYS_CLK_FREQ_DIV_93,
    SYS_CLK_FREQ_DIV_94,
    SYS_CLK_FREQ_DIV_95,
    SYS_CLK_FREQ_DIV_96,
    SYS_CLK_FREQ_DIV_97,
    SYS_CLK_FREQ_DIV_98,
    SYS_CLK_FREQ_DIV_99,
    SYS_CLK_FREQ_DIV_100,
    SYS_CLK_FREQ_DIV_101,
    SYS_CLK_FREQ_DIV_102,
    SYS_CLK_FREQ_DIV_103,
    SYS_CLK_FREQ_DIV_104,
    SYS_CLK_FREQ_DIV_105,
    SYS_CLK_FREQ_DIV_106,
    SYS_CLK_FREQ_DIV_107,
    SYS_CLK_FREQ_DIV_108,
    SYS_CLK_FREQ_DIV_109,
    SYS_CLK_FREQ_DIV_110,
    SYS_CLK_FREQ_DIV_111,
    SYS_CLK_FREQ_DIV_112,
    SYS_CLK_FREQ_DIV_113,
    SYS_CLK_FREQ_DIV_114,
    SYS_CLK_FREQ_DIV_115,
    SYS_CLK_FREQ_DIV_116,
    SYS_CLK_FREQ_DIV_117,
    SYS_CLK_FREQ_DIV_118,
    SYS_CLK_FREQ_DIV_119,
    SYS_CLK_FREQ_DIV_120,
    SYS_CLK_FREQ_DIV_121,
    SYS_CLK_FREQ_DIV_122,
    SYS_CLK_FREQ_DIV_123,
    SYS_CLK_FREQ_DIV_124,
    SYS_CLK_FREQ_DIV_125,
    SYS_CLK_FREQ_DIV_126,
    SYS_CLK_FREQ_DIV_127,
    SYS_CLK_FREQ_DIV_128,

}SysCtr_DivType;

typedef enum
{
    WATCHDOG_TIMER0_CLOCK_GATE = 0,
    WATCHDOG_TIMER1,CLOCK_GATE = 1,

    TIMER0_16_32_CLOCK_GATE = 0,
    TIMER1_16_32_CLOCK_GATE,
    TIMER2_16_32_CLOCK_GATE,
    TIMER3_16_32_CLOCK_GATE,
    TIMER4_16_32_CLOCK_GATE,
    TIMER5_16_32_CLOCK_GATE,

    GPIO_PORTA_CLOCK_GATE = 0,
    GPIO_PORTB_CLOCK_GATE,
    GPIO_PORTC_CLOCK_GATE,
    GPIO_PORTD_CLOCK_GATE,
    GPIO_PORTE_CLOCK_GATE,
    GPIO_PORTF_CLOCK_GATE,

    DMA_CLOCK_GATE = 0,
    HIB_CLOCK_GATE = 0,

    UART_MODULE0_CLOCK_GATE = 0,
    UART_MODULE1_CLOCK_GATE,
    UART_MODULE2_CLOCK_GATE,
    UART_MODULE3_CLOCK_GATE,
    UART_MODULE4_CLOCK_GATE,
    UART_MODULE5_CLOCK_GATE,
    UART_MODULE6_CLOCK_GATE,
    UART_MODULE7_CLOCK_GATE,

    SSI_MODULE0_CLOCK_GATE = 0,
    SSI_MODULE1_CLOCK_GATE, 
    SSI_MODULE2_CLOCK_GATE, 
    SSI_MODULE3_CLOCK_GATE,

    TIMER0_32_64_CLOCK_GATE = 0,
    TIMER1_32_64_CLOCK_GATE,
    TIMER2_32_64_CLOCK_GATE,
    TIMER3_32_64_CLOCK_GATE,
    TIMER4_32_64_CLOCK_GATE,
    TIMER5_32_64_CLOCK_GATE,

}SysCtrl_ClockGateType;

typedef struct 
{
    uint8 ClockSource;
    uint8 CrystalFreq;
    uint8 SysFreqDiv;

}SysCtrl_CfgTypes;

typedef struct 
{
    uint16 Peripheral;
    SysCtrl_ClockGateType PeripheralModule;

}SysCtrl_PheriphralCfgTypes;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
void SYSCTRL_init (SysCtrl_CfgTypes* Config_Ptr);


/******************************************************************************
* \Syntax          : void SYSCTRL_periphralEnableClock (void)        
* \Description     : Set clock for each periphral                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Config_Ptr                        
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void SYSCTRL_periphralEnableClock (SysCtrl_PheriphralCfgTypes* Config_Ptr);

#endif  /* SYSCTRL_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: sysctrl_interface.h
 *********************************************************************************************************************/