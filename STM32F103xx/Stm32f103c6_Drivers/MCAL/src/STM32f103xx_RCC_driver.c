/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	1 OCT 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/


#include "STM32f103xx_RCC_driver.h"
/**================================================================
 * @Fn			- RCC_enuInitConfig
 * @brief 		- This Function Used to Initialize RCC Configuration that User Build in file [STM32f103xx_RCC_driver.h]
 * @param [in] 	- none
 * @param [out] - none
 * @retval 		- ErrorState Which indicate that function works well or not
 */
ES_t RCC_enuInitConfig(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if RCC_CLOCK_TYPE == RCC_HSI
	//Bits 1:0 SW[1:0] @reg CFGR: HSI selected as system clock
	RCC->CFGR &=~ (1<<0);
	RCC->CFGR &=~ (1<<0);
	//Bit 0 @reg CR HSION: Internal high-speed clock enable
	RCC->CR |= (1<<0);
	//Bit 1 HSIRDY: Internal high-speed clock ready flag
	//Check HSI IS READY (Stable)
	while((1&(RCC->CR>>1)) == 0);
	Local_enuErrorState = ES_OK;
#elif RCC_CLOCK_TYPE == RCC_HSE_BYPASS
	/* The HSEBYP Can Be Written Only When HSE Oscilator Is Disabled */
	/* HSE Clock Disabled */
	RCC->CR &=~ (1<<16);
	//Enable HSEBYP: External high-speed clock bypass
	RCC->CR |= (1<<18);
	//Bits 1:0 SW[1:0] @reg CFGR: HSE selected as system clock
	RCC->CFGR |=  (1<<0);
	RCC->CFGR &=~ (1<<0);
	//enable clock on HSE by write one @Bit 16
	RCC->CR |=(1<<16);
	//Bit 17 HSERDY: External high-speed clock ready flag
	//Check HSE IS READY (Stable)
	while((1&(RCC->CR>>17))==0);
#elif RCC_CLOCK_TYPE == RCC_HSE
	//Bits 1:0 SW[1:0] @reg CFGR: HSE selected as system clock
	RCC->CFGR |=  (1<<0);
	RCC->CFGR &=~ (1<<0);
	//enable clock on HSE by write one @Bit 16
	RCC->CR |=(1<<16);
	//Bit 17 HSERDY: External high-speed clock ready flag
	//Check HSE IS READY (Stable)
	while((1&(RCC->CR>>17))==0);
	Local_enuErrorState = ES_OK;
#elif RCC_CLOCK_TYPE == RCC_PLL
	//Bits 1:0 SW[1:0] @reg CFGR: PLL selected as system clock
	RCC->CFGR &=~ (1<<0);
	RCC->CFGR |= (1<<0);
	//Check if MUL Value is in Correct Range
	#if	(RCC_PLL_MUL_VAL >= NO_CLOCK_FACTOR) && (RCC_PLL_MUL_VAL <= PLL_Clock_MULTIPLE_BY_9)
	RCC->CFGR &= ~((0xF)<<18);
	RCC->CFGR |= ((RCC_PLL_MUL_VAL)<<18);
	#elif (RCC_PLL_MUL_VAL < NO_CLOCK_FACTOR) || (RCC_PLL_MUL_VAL > PLL_Clock_MULTIPLE_BY_9)
		#warning "Wrong PLL Multiplication factor!"
	#endif
	//Check for PLL input Source
	#if RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		//enable clock on HSE by write one @Bit 16
		RCC->CR |=(1<<16);
		//Select HSE an input for PLL
		RCC->CFGR |= (1<<16);
		//If bits[3:1] in register RCC_CFGR2 are not set, this bit controls if PREDIV1 divides its input clock by
		//2 (PLLXTPRE=1) or not (PLLXTPRE=0).
		//(HSE/2)
		RCC->CFGR |= (1<<17);
	#elif RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		//Select HSE an input for PLL
		RCC->CFGR |= (1<<16);
	#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		//enable clock on HSE by write one @Bit 16
		RCC->CR |=(1<<16);
		//Select HSE an input for PLL
		RCC->CFGR |= (1<<16);
		//If bits[3:1] in register RCC_CFGR2 are not set, this bit controls if PREDIV1 divides its input clock by
		//2 (PLLXTPRE=1) or not (PLLXTPRE=0).
		//(HSE only) no division
		RCC->CFGR &= ~ (1<<17);
	#endif
		//PLL Enable
		RCC->CR |= (1<<24);
		Local_enuErrorState = ES_OK;
#endif
return Local_enuErrorState;
}
