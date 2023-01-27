/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	1 OCT 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/
#include "../../../STM32F103c8_Drivers/MCAL/inc/STM32f103xx_NVIC_driver.h"

/**================================================================
 * @Fn			- MNVIC_enuEnableInterrupt
 * @brief 		- Used to Enable Interrupt Line For Specific Peripheral.
 * @param [in] 	- Copy_u8InterruptID Which can be any Interrupt Position Based on Vector Table
 * @param [out] - none
 * @retval 		- Error State to Check That Function Works Without Error
 */
ES_t MNVIC_enuEnableInterrupt  	( uint8_t Copy_u8InterruptID )
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8InterruptID <= Interrupt_DMA2_Channel4_5)
	{
		NVIC_ISER[Copy_u8InterruptID/32] = 1<<(Copy_u8InterruptID%32);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}

	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- MNVIC_enuDisableInterrupt
 * @brief 		- Used to Disable Interrupt Line For Specific Peripheral.
 * @param [in] 	- Copy_u8InterruptID Which can be any Interrupt Position Based on Vector Table
 * @param [out] - none
 * @retval 		- Error State to Check That Function Works Without Error
 */
ES_t MNVIC_enuDisableInterrupt 	( uint8_t Copy_u8InterruptID )
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8InterruptID <= Interrupt_DMA2_Channel4_5)
	{
		NVIC_ICER[Copy_u8InterruptID/32] = 1<<(Copy_u8InterruptID%32);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}


	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- MNVIC_enuSetPending
 * @brief 		- Used to Set Pending Flag For Specific Peripheral interrupt.
 * @param [in] 	- Copy_u8InterruptID Which can be any Interrupt Position Based on Vector Table
 * @param [out] - none
 * @retval 		- Error State to Check That Function Works Without Error
 */
ES_t MNVIC_enuSetPending  ( uint8_t Copy_u8InterruptID )
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8InterruptID <= Interrupt_DMA2_Channel4_5)
	{
		NVIC_ISPR[Copy_u8InterruptID/32] = 1<<(Copy_u8InterruptID%32);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}

	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- MNVIC_enuClearPending
 * @brief 		- Used to Clear Pending Flag For Specific Peripheral interrupt.
 * @param [in] 	- Copy_u8InterruptID Which can be any Interrupt Position Based on Vector Table
 * @param [out] - none
 * @retval 		- Error State to Check That Function Works Without Error
 */
ES_t MNVIC_enuClearPending ( uint8_t Copy_u8InterruptID )
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8InterruptID <= Interrupt_DMA2_Channel4_5)
	{
		NVIC_ICPR[Copy_u8InterruptID/32] = 1<<(Copy_u8InterruptID%32);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}

	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- MNVIC_enuGetActive
 * @brief 		- Used to Get Value of active Flag For Specific Peripheral interrupt.
 * @param [in] 	- Copy_u8InterruptID Which can be any Interrupt Position Based on Vector Table
 * @param [out] - none
 * @retval 		- Return value for active flag which
 * 				 {0: Interrupt not active | 1:Interrupt active}
 */
uint8_t MNVIC_enuGetActive ( uint8_t Copy_u8InterruptID )
{

	return (((NVIC_IABR[Copy_u8InterruptID/32]) >> (Copy_u8InterruptID % 32)) & 1);
}
/**================================================================
 * @Fn			- MNVIC_enuSetInterruptPriority
 * @brief 		- This Function Take the Priority and Interrupt_ID From User and set Priority
 * @param [in] 	- Copy_u8InterruptID Which can be any Interrupt Position Based on Vector Table
 * @param [in] 	- Copy_u8InterruptPriority which be the interrupt priority
 * @param [out] - none
 * @retval 		- Return value for active flag which
 */
ES_t NVIC_enuSetPriority  (uint8_t Copy_u8InterruptID , uint8_t Copy_u8InterruptPriority)
{
	ES_t Local_enuErrorState = ES_NOK;
	//Calculate IPR[index] Which Register That Interrupt Found
	uint8_t	Local_u8IPR_index   = Copy_u8InterruptID / 4 ;
	//Calculate Which Section in IPR[index] That Can I ADD Priority for this Register
	uint8_t	Local_u8IPR_Section = Copy_u8InterruptID % 4 ;
	//Calculate The Amount of Shift because i have 4 bit not allowed to write at it
	uint8_t Local_u8IPR_Shift	= (8*Local_u8IPR_Section) + (8-NO_PRIORTY_BITS_IMP);

	NVIC_IPR[Local_u8IPR_index] |= (Copy_u8InterruptPriority << Local_u8IPR_Shift);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;

}
