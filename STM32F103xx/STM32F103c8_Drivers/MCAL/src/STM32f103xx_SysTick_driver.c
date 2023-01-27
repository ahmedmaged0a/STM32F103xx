/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	13 OCT 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/

#include "../../../STM32F103c8_Drivers/MCAL/inc/STM32f103xx_SysTick_driver.h"

void (*STK_VPtrFun) (void);
//Macro for Check in ISR [Single or Periodic]
static __vo uint8_t STK_u8CheckStatus;

/**================================================================
 * @Fn			- MSTK_enuInit
 * @brief 		- Used to initialize Clock of SysTick [AHB or AHB/8].
 * @param [in] 	- Copy_u8Clock to be between (AHB , AHB/8)
 * @param [out] - none
 * @retval 		- Error State to Check That Function Works Without Error
 */
ES_t MSTK_enuInit (uint8_t Copy_u8Clock)
{

	ES_t Local_enuErrorState = ES_NOK;
	switch(Copy_u8Clock)
	{
	case SYS_AHB_0:
		SYSTICK->CTRL |= (1<<2);	//Selects the clock source Processor clock (AHB)
		Local_enuErrorState = ES_OK;
		break;
	case SYS_AHB_8:
		SYSTICK->CTRL &= ~ (1<<2); //Selects the clock source AHB/8
		Local_enuErrorState = ES_OK;
		break;
	}
	SYSTICK->CTRL |= 	(1<<1); // Enable SysTick exception request [interrupt]
	SYSTICK->CTRL &=~ 	(1<<0);	// Counter Disable
	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- MSTK_enuSetBusyWait
 * @brief 		- This function like delay make Processor Busy until Count Done.
 * @param [in] 	- Copy_u32Ticks number of ticks entered by user
 * @param [out] - none
 * @retval 		- Error State to Check That Function Works Without Error
 */
ES_t MSTK_enuSetBusyWait (uint32_t Copy_u32Ticks)
{
	ES_t Local_enuErrorState = ES_OK;
	//CLear Value Register
	SYSTICK->VAL = 0;
	//Set Load Register With the Value [Copy_u32Ticks]
	SYSTICK->LOAD = Copy_u32Ticks-1;
	//Enable SYSTICK
	SYSTICK->CTRL |=    (1<<0);
	//Disable Interrupt
	SYSTICK->CTRL &=~ 	(1<<1);
	//Busy until Count Done
	while((1 & (SYSTICK->CTRL >> 16)) == 0);
	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- MSTK_enuSetIntervalSingle
 * @brief 		- This function Make a single shot Count and stop the counter.
 * @param [in] 	- Copy_u32Ticks number of ticks entered by user
 * @param [in] 	- Copy_Vptr Pointer to user Function
 * @retval 		- Error State to Check That Function Works Without Error
 */
ES_t MSTK_enuSetIntervalSingle (uint32_t Copy_u32Ticks , void (*Copy_Vptr)(void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if (Copy_Vptr != NULL)
	{
		//Set STK_CheckStatus
		STK_u8CheckStatus = STK_SINGLE;
		//CLear Value Register
		SYSTICK->VAL = 0;
		//Set Load Register With the Value [Copy_u32Ticks]
		SYSTICK->LOAD = Copy_u32Ticks-1;
		//Enable Interrupt
		SYSTICK->CTRL |=	(1<<1);
		//Set CallBack Function
		STK_VPtrFun = Copy_Vptr;
		//Enable SYSTICK
		SYSTICK->CTRL |=    (1<<0);

		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- MSTK_enuSetIntervalPeriodic
 * @brief 		- This function Make a Periodic Count [Counter not stopped].
 * @param [in] 	- Copy_u32Ticks number of ticks entered by user
 * @param [in] 	- Copy_Vptr Pointer to user Function
 * @retval 		- Error State to Check That Function Works Without Error
 */
ES_t MSTK_enuSetIntervalPeriodic (uint32_t Copy_u32Ticks , void (*Copy_Vptr)(void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if (Copy_Vptr != NULL)
	{
		//Set CallBack Function
		STK_VPtrFun = Copy_Vptr;
		//Set STK_CheckStatus
		STK_u8CheckStatus = STK_PERIODIC;
		//CLear Value Register
		SYSTICK->VAL = 0;
		//Set Load Register With the Value [Copy_u32Ticks]
		SYSTICK->LOAD = Copy_u32Ticks-1;
		//Enable Interrupt
		SYSTICK->CTRL |=	(1<<1);
		//Enable SYSTICK
		SYSTICK->CTRL |=    (1<<0);
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- MSTK_enuStopInterval
 * @brief 		- This function Stop the Counter of SysTick and also Stop the interrupt.
 * @param [in] 	- none
 * @param [out] - none
 * @retval 		- Error State to Check That Function Works Without Error
 */
ES_t MSTK_enuStopInterval (void)
{
	ES_t Local_enuErrorState = ES_OK;
	SYSTICK->LOAD = 0;
	//Disable Interrupt
	SYSTICK->CTRL &=~	 (1<<1);
	//Disable SYSTICK
	SYSTICK->CTRL &=~    (1<<0);

	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- MSTK_enuGetElapsedTime
 * @brief 		- This function return to the user Elapsed time [Load - Value]
 * @param [in] 	- Copy_Pu32Time this Variable of User to return value
 * @param [out] - none
 * @retval 		- Error State to Check That Function Works Without Error
 */
ES_t MSTK_enuGetElapsedTime (uint32_t *Copy_Pu32Time)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Pu32Time != NULL)
	{
		//ADD Elapsed Time Which be [Loadtime-Value]
		*Copy_Pu32Time = (SYSTICK->LOAD - SYSTICK->VAL);
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- MSTK_enuGetRemainigTime
 * @brief 		- This function return to the user RemainigTime [Value only]
 * @param [in] 	- Copy_Pu32Time this Variable of User to return value
 * @param [out] - none
 * @retval 		- Error State to Check That Function Works Without Error
 */
ES_t MSTK_enuGetRemainigTime (uint32_t *Copy_Pu32Time)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Pu32Time != NULL)
	{
		//ADD Current Value of  VAL Register
		*Copy_Pu32Time = SYSTICK->VAL;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- _delay_ms
 * @brief 		- This function make a delay in millisecond.
 * @param [in] 	- Copy_u32Time number of time entered by user
 * @param [out] - none
 * @retval 		- Error State to Check That Function Works Without Error
 */
void _delay_ms(uint32_t Copy_u32Time)
{
	//CLear Value Register
	SYSTICK->VAL = 0;
	//Set Load Register With the Value [Copy_u32Ticks]
	SYSTICK->LOAD = (Copy_u32Time-1)*1000;
	//Disable Interrupt
	SYSTICK->CTRL &=~ 	(1<<1);
	//Enable SYSTICK
	SYSTICK->CTRL |=    (1<<0);
	//Busy until Count Done
	while((1 & (SYSTICK->CTRL >> 16)) == 0);
}
//======================================Interrupt Handler========================
void SysTick_Handler(void)
{
	STK_VPtrFun();
	if(STK_u8CheckStatus == STK_SINGLE)
	{
		SYSTICK->LOAD = 0;
		//Disable Interrupt
		SYSTICK->CTRL &=~	 (1<<1);
		//Disable SYSTICK
		SYSTICK->CTRL &=~    (1<<0);
	}
}
