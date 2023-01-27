/*
 * MACROS.h
 *
 *  Created on: JUL 23, 2022
 *      Author: Ahmed Maged
 */

#ifndef INCLUDE_MACROS_H_
#define INCLUDE_MACROS_H_

#define SET_BIT(REG,BITNUM) (REG |=(1<<BITNUM))
#define CLEAR_BIT(REG,BITNUM) (REG &=~(1<<BITNUM))
#define TOG_BIT(REG , BITNUM) REG ^= 1<<BITNUM
#define GET_BIT(REG , BITNUM) ( (REG >> BITNUM) & 1 )


#endif /* INCLUDE_MACROS_H_ */
