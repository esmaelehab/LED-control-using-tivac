/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  dio_program.c
 *        \brief  source file for the dio driver
 *
 *      \details write, read channels and ports in the tiva-c 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "mcu_hw.h"
#include "bit_math.h"
#include "std_types.h"
#include "dio_private.h"
#include "dio_interface.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/* array to hold the base address for each port*/
static volatile uint32 PortBaseAddr_Arr[NUM_OF_PORTS] = {
     PORT_A_BASE_ADDRESS, PORT_B_BASE_ADDRESS, PORT_C_BASE_ADDRESS, PORT_D_BASE_ADDRESS, PORT_E_BASE_ADDRESS, PORT_F_BASE_ADDRESS};

static volatile uint32 Addr = 0x0;

static volatile uint16 GPIO_DATA_MASK = 0x0;

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
Dio_LevelType DIO_readChannel (Dio_ChannelType a_channelId)
{
    Dio_LevelType value;
    Dio_PortType portNum = a_channelId / NUM_OF_CHANNELS;
    Dio_ChannelType channelPos = a_channelId % NUM_OF_CHANNELS;

    GPIO_DATA_MASK = 1<<(channelPos+2);
    Addr = PortBaseAddr_Arr[portNum] + (uint32)GPIO_DATA_MASK;

    value = GPIODATA(Addr)>> channelPos;
    return value;
}

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
void DIO_writeChannel (Dio_ChannelType a_channelId, Dio_LevelType a_level)
{
    Dio_PortType portNum = a_channelId / NUM_OF_CHANNELS;
    Dio_ChannelType channelPos = a_channelId % NUM_OF_CHANNELS;

    GPIO_DATA_MASK = 1<<(channelPos+2);
    Addr = PortBaseAddr_Arr[portNum] + (uint32)GPIO_DATA_MASK;
    
    GPIODATA(Addr) = a_level<<channelPos;  
}

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
Dio_PortLevelType DIO_readPort (Dio_PortType a_portId)
{
    Dio_PortLevelType value;
    GPIO_DATA_MASK = 0x3FC;
    Addr = PortBaseAddr_Arr[a_portId] + (uint32)GPIO_DATA_MASK;

    value = GPIODATA(Addr);
    return value;
}

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
void Dio_WritePort (Dio_PortType a_portId, Dio_PortLevelType a_level)
{
    GPIO_DATA_MASK = a_level<<2;
    Addr = PortBaseAddr_Arr[a_portId] + (uint32)GPIO_DATA_MASK;
    
    GPIODATA(Addr) = a_level; 
}

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
void Dio_FlipChannel (Dio_ChannelType a_channelId)
{
    Dio_PortType portNum = a_channelId / NUM_OF_CHANNELS;
    Dio_ChannelType channelPos = a_channelId % NUM_OF_CHANNELS;

    GPIO_DATA_MASK = 1<<(channelPos+2);
    Addr = PortBaseAddr_Arr[portNum] + (uint32)GPIO_DATA_MASK;
    
    TOGGLE_BIT(GPIODATA(Addr), channelPos);
}

/**********************************************************************************************************************
 *  END OF FILE: dio_program.c
 *********************************************************************************************************************/