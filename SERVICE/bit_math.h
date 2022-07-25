/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  bit_math.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  Provision of Standard Types
 *
 *********************************************************************************************************************/



#ifndef BIT_MATH_H
#define BIT_MATH_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define SET_BIT(REG,BIT)      (REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT)    (REG&=(~(1<<BIT)))
#define TOGGLE_BIT(REG,BIT)   (REG^=(1<<BIT))

#define BIT_IS_SET(REG,BIT)   (REG&(1<<BIT))
#define BIT_IS_CLEAR(REG,BIT) (!(REG&(1<<BIT)))


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* STD_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: bit_math.h
 *********************************************************************************************************************/