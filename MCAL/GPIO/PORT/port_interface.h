/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  port_interface.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_INTERFACE_H
#define PORT_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define PIN_X_MODE_AIN           1
#define PIN_X_MODE_DIO           0

#define PIN_A0_MODE_U0Rx         1
#define PIN_A0_MODE_CAN1Rx       8

#define PIN_A1_MODE_U0Tx         1 
#define PIN_A1_MODE_CAN1Tx       8

#define PIN_A2_MODE_SSI0CLk      2

#define PIN_A3_MODE_SSI0Fss      2

#define PIN_A4_MODE_SSI0Rx       2

#define PIN_A5_MODE_SSI0Tx       2

#define PIN_A6_MODE_I2C1SCL      3 
#define PIN_A6_MODE_M1PWM2       5

#define PIN_A7_MODE_I2C1SDA      3
#define PIN_A7_MODE_M1PWM3       5

#define PIN_B0_MODE_U1Rx         1
#define PIN_B0_MODE_T2CCP0       7

#define PIN_B1_MODE_U1Tx         1
#define PIN_B1_MODE_T2CCP1       7

#define PIN_B2_MODE_I2C0SCL      3
#define PIN_B2_MODE_T3CCP0       7

#define PIN_B3_MODE_I2C0SDA      3
#define PIN_B3_MODE_T3CCP1       7
        
#define PIN_B4_MODE_SSI2Clk      2
#define PIN_B4_MODE_M0PWM2       4
#define PIN_B4_MODE_T1CCP0       7
#define PIN_B4_MODE_CAN0Rx       8

#define PIN_B5_MODE_SSI2Fss      2  
#define PIN_B5_MODE_M0PWM3       4
#define PIN_B5_MODE_T1CCP1       7
#define PIN_B5_MODE_CAN0Tx       8

#define PIN_B6_MODE_SSI2Rx       2
#define PIN_B6_MODE_M0PWM0       4
#define PIN_B6_MODE_T0CCP0       7

#define PIN_B7_MODE_SSI2Tx       2
#define PIN_B7_MODE_M0PWM1       4
#define PIN_B7_MODE_T0CCP1       7


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
    PORT_CHANNEL_A0,
    PORT_CHANNEL_A1,
    PORT_CHANNEL_A2,
    PORT_CHANNEL_A3,
    PORT_CHANNEL_A4,
    PORT_CHANNEL_A5,
    PORT_CHANNEL_A6,
    PORT_CHANNEL_A7,

    PORT_CHANNEL_B0,
    PORT_CHANNEL_B1,
    PORT_CHANNEL_B2,
    PORT_CHANNEL_B3,
    PORT_CHANNEL_B4,
    PORT_CHANNEL_B5,
    PORT_CHANNEL_B6,
    PORT_CHANNEL_B7,

    PORT_CHANNEL_C0,
    PORT_CHANNEL_C1,
    PORT_CHANNEL_C2,
    PORT_CHANNEL_C3,
    PORT_CHANNEL_C4,
    PORT_CHANNEL_C5,
    PORT_CHANNEL_C6,
    PORT_CHANNEL_C7,

    PORT_CHANNEL_D0,
    PORT_CHANNEL_D1,
    PORT_CHANNEL_D2,
    PORT_CHANNEL_D3,
    PORT_CHANNEL_D4,
    PORT_CHANNEL_D5,
    PORT_CHANNEL_D6,
    PORT_CHANNEL_D7,

    PORT_CHANNEL_E0,
    PORT_CHANNEL_E1,
    PORT_CHANNEL_E2,
    PORT_CHANNEL_E3,
    PORT_CHANNEL_E4,
    PORT_CHANNEL_E5,
    PORT_CHANNEL_E6_NA,
    PORT_CHANNEL_E7_NA,

    PORT_CHANNEL_F0,
    PORT_CHANNEL_F1,
    PORT_CHANNEL_F2,
    PORT_CHANNEL_F3,
    PORT_CHANNEL_F4,

}Port_PinType;


typedef enum
{
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F

}Port_Type;

typedef enum
{
    INPUT = 0,
    OUTPUT = 1

}Port_PinDirectionType;

typedef enum
{
    NO_ATTACH,
    PULL_UP,
    PULL_DOWN,
    OPEN_DRAIN

}Port_PinInternalAttachType;

typedef uint8 Port_PinModeType;

typedef enum
{
    CURRENT_2mA,
    CURRENT_4mA,
    CURRENT_8mA,

}Port_PinOutputCurrentType;

typedef enum
{
    INTERRUPT_DISABLE,
    INTERRUPT_FALLING_EDGE,
    INTERRUPT_RISING_EDGE,
    INTERRUPT_BOTH_EDGES,
    INTERRUPT_HIGH_LEVEL,
    INTERRUPT_LOW_LEVEL

}Port_InterruptType;

typedef struct
{
    Port_PinType Pin_ID;
    Port_PinDirectionType Direction;
    Port_PinInternalAttachType Attach;
    Port_PinModeType Mode;
    Port_PinOutputCurrentType Current;
    Port_InterruptType Interrupt;
    
}Port_CfgType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
* \Parameters (in) : Config_Ptr pointer to array of struct for the configuration                      
* \Parameters (out): None                                                      
* \Return value:   : None                                  
**********************************************************************************/
void PORT_init (Port_CfgType* Config_Ptr);

 
#endif  /* PORT_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_interface.h
 *********************************************************************************************************************/