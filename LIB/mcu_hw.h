/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  mcu_hw.h
 *       Module:  mcu_hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/****************************************************************************************************************
 *                                                                                                              *
 *                                      INTERRUPT CONTROL MODULE REGISTERS                                      *
 *                                                                                                              *
 ***************************************************************************************************************/

#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define SYSPRI1                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SYSPRI2                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
#define SYSPRI3                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
#define SYSHNDCTRL                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24))
#define PRIx(INTERRUPT_NUM)                    *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+(0x400 +((INTERRUPT_NUM/4U)*4))))
#define ENx(INTERRUPT_NUM)                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+(0x100 +((INTERRUPT_NUM/32U)*4))))
#define STCTRL                                 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x010))


/****************************************************************************************************************
 *                                                                                                              *
 *                                      SYSTEM CONTROL MODULE REGISTERS                                         *
 *                                                                                                              *
 ***************************************************************************************************************/

#define SYSTEM_CONTROL_BASE_ADDRESS            0x400FE000

#define RCC                                    *((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS+0x060))
#define RCC2                                   *((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS+0x070))
#define RIS                                    *((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS+0x050))
#define RCGC(PERIPHERAL_OFFSET)                *((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS+PERIPHERAL_OFFSET))


/****************************************************************************************************************
 *                                                                                                              *
 *                                         GPIO MODULE REGISTERS                                                *
 *                                                                                                              *
 ***************************************************************************************************************/

#define PORT_A_BASE_ADDRESS                     0x40004000
#define PORT_B_BASE_ADDRESS                     0x40005000
#define PORT_C_BASE_ADDRESS                     0x40006000
#define PORT_D_BASE_ADDRESS                     0x40007000
#define PORT_E_BASE_ADDRESS                     0x40024000
#define PORT_F_BASE_ADDRESS                     0x40025000

#define GPIO_DATA_OFFSET                        0x000
#define GPIO_DIRECTION_OFFSET                   0x400
#define GPIO_INTERRUPT_SENSE_OFFSET             0x404
#define GPIO_INTERRUPT_BOTH_EDGE_OFFSET         0x408
#define GPIO_INTERRUPT_EVENT_OFFSET             0x40C
#define GPIO_INTERRUPT_MASK_OFFSET              0x410
#define GPIO_RAW_INTERRUPT_STATUS_OFFSET        0x414
#define GPIO_MASK_INTERRUPT_STATUS_OFFSET       0x418
#define GPIO_INTERRUPT_CLEAR_OFFSET             0x41C
#define GPIO_ALTERNATE_FUNC_SEL_OFFSET          0x420
#define GPIO_2_MA_DRIVE_SEL_OFFSET              0x500
#define GPIO_4_MA_DRIVE_SEL_OFFSET              0x504
#define GPIO_8_MA_DRIVE_SEL_OFFSET              0x508
#define GPIO_OPEN_DRAIN_SEL_OFFSET              0x50C
#define GPIO_PULL_UP_SEL_OFFSET                 0x510
#define GPIO_PULL_DOWN_SEL_OFFSET               0x514
#define GPIO_SLEW_RATE_CONTROL_SEL_OFFSET       0x518
#define GPIO_DIGITAL_EN_OFFSET                  0x51C
#define GPIO_LOCK_OFFSET                        0x520
#define GPIO_COMMIT_OFFSET                      0x524
#define GPIO_ANALOG_MODE_SEL_OFFSET             0x528
#define GPIO_PORT_CONTROL_OFFSET                0x52C
#define GPIO_ADC_CONTROL_OFFSET                 0x530
#define GPIO_DMA_CONTROL_OFFSET                 0x534


#define GPIODATA(BASE_ADDR)                    *((volatile uint32*)((BASE_ADDR)+GPIO_DATA_OFFSET))
#define GPIODIR(BASE_ADDR)                     *((volatile uint32*)((BASE_ADDR)+GPIO_DIRECTION_OFFSET))
#define GPIOIS(BASE_ADDR)                      *((volatile uint32*)((BASE_ADDR)+GPIO_INTERRUPT_SENSE_OFFSET))      
#define GPIOIBE(BASE_ADDR)                     *((volatile uint32*)((BASE_ADDR)+GPIO_INTERRUPT_BOTH_EDGE_OFFSET))     
#define GPIOIEV(BASE_ADDR)                     *((volatile uint32*)((BASE_ADDR)+GPIO_INTERRUPT_EVENT_OFFSET))
#define GPIOIM(BASE_ADDR)                      *((volatile uint32*)((BASE_ADDR)+GPIO_INTERRUPT_MASK_OFFSET)) 
#define GPIORIS(BASE_ADDR)                     *((volatile uint32*)((BASE_ADDR)+GPIO_RAW_INTERRUPT_STATUS_OFFSET))  
#define GPIOMIS(BASE_ADDR)                     *((volatile uint32*)((BASE_ADDR)+GPIO_MASK_INTERRUPT_STATUS_OFFSET))
#define GPIOICR(BASE_ADDR)                     *((volatile uint32*)((BASE_ADDR)+GPIO_INTERRUPT_CLEAR_OFFSET))
#define GPIOAFSEL(BASE_ADDR)                   *((volatile uint32*)((BASE_ADDR)+GPIO_ALTERNATE_FUNC_SEL_OFFSET))
#define GPIODR2R(BASE_ADDR)                    *((volatile uint32*)((BASE_ADDR)+GPIO_2_MA_DRIVE_SEL_OFFSET))
#define GPIODR4R(BASE_ADDR)                    *((volatile uint32*)((BASE_ADDR)+GPIO_4_MA_DRIVE_SEL_OFFSET))
#define GPIODR8R(BASE_ADDR)                    *((volatile uint32*)((BASE_ADDR)+GPIO_8_MA_DRIVE_SEL_OFFSET))
#define GPIOODR(BASE_ADDR)                     *((volatile uint32*)((BASE_ADDR)+GPIO_OPEN_DRAIN_SEL_OFFSET))
#define GPIOPUR(BASE_ADDR)                     *((volatile uint32*)((BASE_ADDR)+GPIO_PULL_UP_SEL_OFFSET))
#define GPIOPDR(BASE_ADDR)                     *((volatile uint32*)((BASE_ADDR)+GPIO_PULL_DOWN_SEL_OFFSET))
#define GPIOSLR(BASE_ADDR)                     *((volatile uint32*)((BASE_ADDR)+GPIO_SLEW_RATE_CONTROL_SEL_OFFSET))
#define GPIODEN(BASE_ADDR)                     *((volatile uint32*)((BASE_ADDR)+GPIO_DIGITAL_EN_OFFSET))
#define GPIOLOCK(BASE_ADDR)                    *((volatile uint32*)((BASE_ADDR)+GPIO_LOCK_OFFSET))
#define GPIOCR(BASE_ADDR)                      *((volatile uint32*)((BASE_ADDR)+GPIO_COMMIT_OFFSET))
#define GPIOAMSEL(BASE_ADDR)                   *((volatile uint32*)((BASE_ADDR)+GPIO_ANALOG_MODE_SEL_OFFSET))
#define GPIOPCTL(BASE_ADDR)                    *((volatile uint32*)((BASE_ADDR)+GPIO_PORT_CONTROL_OFFSET))
#define GPIOADCCTL(BASE_ADDR)                  *((volatile uint32*)((BASE_ADDR)+GPIO_ADC_CONTROL_OFFSET))
#define GPIODMACTL(BASE_ADDR)                  *((volatile uint32*)((BASE_ADDR)+GPIO_DMA_CONTROL_OFFSET))


/****************************************************************************************************************
 *                                                                                                              *
 *                                   GENERAL PURPOSE TIMER MODULE REGISTERS                                     *
 *                                                                                                              *
 ***************************************************************************************************************/


#define GPTM_BASE_ADDRESS(n)								(0x40030000UL+(0x1000*(n))+(0x14000*(n/8)))
#define GPTMCFG(n)											*((volatile uint32*)(GPTM_BASE_ADDRESS(n)))
#define GPTMTAMR(n)                              			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x004)))
#define	GPTMTBMR(n)                              			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x008)))
#define	GPTMCTL(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x00C)))
#define GPTMSYNC(n)											*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x010)))
#define	GPTMIMR(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x018)))
#define	GPTMRIS(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x01C)))
#define	GPTMMIS(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x020)))
#define	GPTMICR(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x024)))
#define GPTMTAILR(n)                             			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x028)))
#define GPTMTBILR(n)                               			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x02C)))
#define GPTMTAMATCHR(n)                          			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x030)))
#define GPTMTBMATCHR(n)                          			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x034)))
#define GPTMTAPR(n)                            				*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x038)))
#define GPTMTBPR(n)                           			    *((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x03C)))
#define GPTMTAPMR(n)                           			    *((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x040)))
#define GPTMTBPMR(n)                           			    *((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x044)))
#define GPTMTAR(n)                           			    *((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x048)))
#define GPTMTBR(n)                           			    *((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x04C)))
#define GPTMTAV(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x050)))
#define GPTMTBV(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x054)))
#define GPTMRTCPD(n)                                		*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x058)))
#define GPTMTAPS(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x05C)))
#define GPTMTBPS(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x060)))
#define GPTMTAPV(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x064)))
#define GPTMTBPV(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x068)))
#define GPTMPP(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0xFC0)))


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/