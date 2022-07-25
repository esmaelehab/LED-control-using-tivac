/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  dio_interface.h
 *       Module:  -
 *
 *  Description:  header file for dio driver interface     
 *  
 *********************************************************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "mcu_hw.h"
#include "std_types.h"
#include "bit_math.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum 
{
    DIO_CHANNEL_A0,
    DIO_CHANNEL_A1,
    DIO_CHANNEL_A2,
    DIO_CHANNEL_A3,
    DIO_CHANNEL_A4,
    DIO_CHANNEL_A5,
    DIO_CHANNEL_A6,
    DIO_CHANNEL_A7,

    DIO_CHANNEL_B0,
    DIO_CHANNEL_B1,
    DIO_CHANNEL_B2,
    DIO_CHANNEL_B3,
    DIO_CHANNEL_B4,
    DIO_CHANNEL_B5,
    DIO_CHANNEL_B6,
    DIO_CHANNEL_B7,

    DIO_CHANNEL_C0,
    DIO_CHANNEL_C1,
    DIO_CHANNEL_C2,
    DIO_CHANNEL_C3,
    DIO_CHANNEL_C4,
    DIO_CHANNEL_C5,
    DIO_CHANNEL_C6,
    DIO_CHANNEL_C7,

    DIO_CHANNEL_D0,
    DIO_CHANNEL_D1,
    DIO_CHANNEL_D2,
    DIO_CHANNEL_D3,
    DIO_CHANNEL_D4,
    DIO_CHANNEL_D5,
    DIO_CHANNEL_D6,
    DIO_CHANNEL_D7,

    DIO_CHANNEL_E0,
    DIO_CHANNEL_E1,
    DIO_CHANNEL_E2,
    DIO_CHANNEL_E3,
    DIO_CHANNEL_E4,
    DIO_CHANNEL_E5,
    DIO_CHANNEL_E6_NA,
    DIO_CHANNEL_E7_NA,

    DIO_CHANNEL_F0,
    DIO_CHANNEL_F1,
    DIO_CHANNEL_F2,
    DIO_CHANNEL_F3,
    DIO_CHANNEL_F4,

}Dio_ChannelType;

typedef enum
{
    DIO_PORT_A,
    DIO_PORT_B,
    DIO_PORT_C,
    DIO_PORT_D,
    DIO_PORT_E,
    DIO_PORT_F

}Dio_PortType;

typedef STD_LevelType Dio_LevelType;

typedef uint8 Dio_PortLevelType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/*****************************************************************************************
* \Syntax          : Dio_LevelType DIO_readChannel (Dio_ChannelType a_channelId)        
* \Description     : calculate the port and channel numbers and data mask value
*                    read the required channel                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : a_channelId   channel number                      
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType  , STD_levelType                                               
******************************************************************************************/
Dio_LevelType DIO_readChannel (Dio_ChannelType a_channelId);

/***********************************************************************************************
* \Syntax          : void DIO_writeChannel (Dio_ChannelType a_channelId, Dio_LevelType a_level)        
* \Description     : calculate the port and channel numbers and the data mask value 
*                    write the required value                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : a_channelId   channel num
*                    a_level       value to be written           
* \Parameters (out): None                                                      
* \Return value:   : None                                  
***********************************************************************************************/
void DIO_writeChannel (Dio_ChannelType a_channelId, Dio_LevelType a_level);

/*****************************************************************************************
* \Syntax          : Dio_PortLevelType DIO_readPort (Dio_PortType a_portId)        
* \Description     : read the required port value                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : a_portId   port number                      
* \Parameters (out): None                                                      
* \Return value:   : Dio_PortLevelType  , uint8                                               
******************************************************************************************/
Dio_PortLevelType DIO_readPort (Dio_PortType a_portId);

/***********************************************************************************************
* \Syntax          : void Dio_WritePort (Dio_PortType a_portId, Dio_PortLevelType a_level)        
* \Description     : calculate the data mask value write the required value                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : a_portId      port num
*                    a_level       value to be written           
* \Parameters (out): None                                                      
* \Return value:   : None                                  
***********************************************************************************************/
void Dio_WritePort (Dio_PortType a_portId, Dio_PortLevelType a_level);

/******************************************************************************
* \Syntax          : void Dio_FlipChannel (Dio_ChannelType a_channelId)        
* \Description     : calculate the port and channel number and toggle it                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : a_channelId   channel number                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Dio_FlipChannel (Dio_ChannelType a_channelId);

 
#endif  /* DIO_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: dio_inteface.h
 *********************************************************************************************************************/