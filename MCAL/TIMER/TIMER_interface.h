/*
 * Timer_interface.h
 *
 *  Created on: Mar 20, 2021
 *      Author: Kishk
 */

#ifndef MCAL_05__TIMER_TIMER_INTERFACE_H_
#define MCAL_05__TIMER_TIMER_INTERFACE_H_


#define TIMER_u8_TIMER_0	0
#define TIMER_u8_TIMER_1	1
#define TIMER_u8_TIMER_2	2


#define TIMER1_CHANNEL_A_ENABLE		3
#define TIMER1_CHANNEL_B_ENABLE		4


/*				TIMER0					*/
#define TIMER0_u8_NORMAL				0
#define TIMER0_u8_PWM_PHASE_CORRECT		1
#define TIMER0_u8_CTC					2
#define TIMER0_u8_FAST_PWM				3


#define TIMER0_u8_OC0_DISCONNECTED		0
#define TIMER0_u8_OC0_TOGGLE			1
#define TIMER0_u8_OC0_CLEAR				2
#define TIMER0_u8_OC0_SET				3


#define	TIMER0_u8_STOP					0
#define	TIMER0_u8_DIV_BY_1				1
#define TIMER0_u8_DIV_BY_8				2
#define TIMER0_u8_DIV_BY_64				3
#define TIMER0_u8_DIV_BY_256			4
#define TIMER0_u8_DIV_BY_1024			5


#define	TIMER0_u8_DISABLE_INTERRUPT		0
#define	TIMER0_u8_ENABLE_INTERRUPT		1





/*				TIMER1					*/
#define TIMER1_u8_NORMAL								0
#define TIMER1_u8_PWM_PHASE_CORRECT_8BIT				1
#define TIMER1_u8_PWM_PHASE_CORRECT_9BIT				2
#define TIMER1_u8_PWM_PHASE_CORRECT_10BIT				3
#define TIMER1_u8_CTC_OCR1A								4
#define TIMER1_u8_FAST_PWM_8BIT							5
#define TIMER1_u8_FAST_PWM_9BIT							6
#define TIMER1_u8_FAST_PWM_10BIT						7
#define TIMER1_u8_PWM_PHASE_FREQUANCY_CORRECT_ICR1		8
#define TIMER1_u8_PWM_PHASE_FREQUANCY_CORRECT_OCR1A		9
#define TIMER1_u8_PWM_PHASE_CORRECT_ICR1				10
#define TIMER1_u8_PWM_PHASE_CORRECT_OCR1A				11
#define TIMER1_u8_CTC_ICR1								12
#define TIMER1_u8_FAST_PWM_ICR1							13
#define TIMER1_u8_FAST_PWM_OCR1A						14




#define TIMER1_u8_OC1_DISCONNECTED			0
#define TIMER1_u8_OC1_TOGGLE				1
#define TIMER1_u8_OC1_CLEAR					2
#define TIMER1_u8_OC1_SET					3


#define	TIMER1_u8_STOP						0
#define	TIMER1_u8_DIV_BY_1					1
#define TIMER1_u8_DIV_BY_8					2
#define TIMER1_u8_DIV_BY_64					3
#define TIMER1_u8_DIV_BY_256				4
#define TIMER1_u8_DIV_BY_1024				5


#define	TIMER1_u8_FALLING_INPUT_CAPTURE		0
#define	TIMER1_u8_RISING_INPUT_CAPTURE		1




/*            	TIMER FUNCTIONS	PART				*/

typedef enum
{
	Timer_Normal_Mode,
	Timer_CTC_Mode
}Timer_Modes;

typedef enum
{
	Timer_Interrupt_Enable,
	Timer_Interrupt_Disable
}Timer_Interrupt;


typedef enum
{
	NO_CLK_SRC,
	NO_PRESCALAR,
	PRESCALAR_CLK8,
	PRESCALAR_CLK64,
	PRESCALAR_CLK256,
	PRESCALAR_CLK1024,
	EXT_CLK_FALLING=6,
	EXT_CLK_RISING
}Timer_PRESCALAR;

typedef	struct
{
	u8 Timer;
	Timer_Modes 	Timer_Mode;
	Timer_PRESCALAR	Timer_Prescaller;
	Timer_Interrupt Timer_OVF_INT;
	Timer_Interrupt Timer_CTC_INT;

}Timer_Configration;


void TIMER_voidInit(void);
//void TIMER_voidPostInit(const Timer_Configration *  Cpy_Configuration);
void TIMER_voidSetOVFRegister(u8 Copy_u8Timer , u16 Copy_u16Value);
void TIMER_voidSetCTCRegister(u8 Copy_u8Timer , u16 Copy_u16Value);

void TIMER_voidEnableOVFINT(u8 Copy_u8Timer);
void TIMER_voidDisableOVFINT(u8 Copy_u8Timer);
void TIMER_voidClearOVFFlag(u8 Copy_u8Timer);


void TIMER_voidEnableCTCINT(u8 Copy_u8Timer);
void TIMER_voidDisableCTCINT(u8 Copy_u8Timer);
void TIMER_voidClearCTCFlag(u8 Copy_u8Timer);




void TIMER0_voidSetOVFCallBack(void (*Copy_pvoidCallBack) (void));
void TIMER0_voidSetCTCCallBack(void (*Copy_pvoidCallBack) (void));

void TIMER0_voidForceOutputCompare(void);



#endif /* MCAL_05__TIMER_TIMER_INTERFACE_H_ */
