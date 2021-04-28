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



/*				TIMER2					*/
#define TIMER2_u8_NORMAL				0
#define TIMER2_u8_PWM_PHASE_CORRECT		1
#define TIMER2_u8_CTC					2
#define TIMER2_u8_FAST_PWM				3


#define TIMER2_u8_OC2_DISCONNECTED		0
#define TIMER2_u8_OC2_TOGGLE			1
#define TIMER2_u8_OC2_CLEAR				2
#define TIMER2_u8_OC2_SET				3


#define	TIMER2_u8_STOP					0
#define	TIMER2_u8_DIV_BY_1				1
#define TIMER2_u8_DIV_BY_8				2
#define TIMER2_u8_DIV_BY_32				3
#define TIMER2_u8_DIV_BY_64				4
#define TIMER2_u8_DIV_BY_128			5
#define TIMER2_u8_DIV_BY_256			6
#define TIMER2_u8_DIV_BY_1024			7


#define	TIMER2_u8_DISABLE_INTERRUPT		0
#define	TIMER2_u8_ENABLE_INTERRUPT		1



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

/*										TIMER0											*/

void TIMER0_voidSetOVFRegister(u8 Copy_u8Value);
void TIMER0_voidSetCTCRegister(u8 Copy_u8Value);

void TIMER0_voidEnableOVFINT(void);
void TIMER0_voidDisableOVFINT(void);
void TIMER0_voidClearOVFFlag(void);


void TIMER0_voidEnableCTCINT(void);
void TIMER0_voidDisableCTCINT(void);
void TIMER0_voidClearCTCFlag(void);




void TIMER0_voidSetOVFCallBack(void (*Copy_pvoidCallBack) (void));
void TIMER0_voidSetCTCCallBack(void (*Copy_pvoidCallBack) (void));

void TIMER0_voidForceOutputCompare(void);


/*										TIMER1											*/
void TIMER1_voidSetOVFRegister(u16 Copy_u16Value);
void TIMER1_voidChannelASetCTCRegister(u16 Copy_u16Value);
void TIMER1_voidChannelBSetCTCRegister(u16 Copy_u16Value);
u16	 TIMER1_u16InputCaptureValue(void);


void TIMER1_voidEnableOVFINT(void);
void TIMER1_voidDisableOVFINT(void);
void TIMER1_voidClearOVFFlag(void);


void TIMER1_voidChannelAEnableCTCINT(void);
void TIMER1_voidChannelADisableCTCINT(void);
void TIMER1_voidChannelAClearCTCFlag(void);

void TIMER1_voidChannelBEnableCTCINT(void);
void TIMER1_voidChannelBDisableCTCINT(void);
void TIMER1_voidChannelBClearCTCFlag(void);

void TIMER1_voidEnableInputCaptureINT(void);
void TIMER1_voidDisableInputCaptureINT(void);
void TIMER1_voidClearInputCaptureFlag(void);

void TIMER1_voidSetOVFCallBack(void (*Copy_pvoidCallBack) (void));
void TIMER1_voidChannelASetCTCCallBack(void (*Copy_pvoidCallBack) (void));
void TIMER1_voidChannelBSetCTCCallBack(void (*Copy_pvoidCallBack) (void));
void TIMER1_voidSetInputCaptureCallBack(void (*Copy_pvoidCallBack) (void));

void TIMER1_voidChannelAForceOutputCompare(void);
void TIMER1_voidChannelBForceOutputCompare(void);



/*										TIMER2											*/

void TIMER2_voidSetOVFRegister(u8 Copy_u8Value);
void TIMER2_voidSetCTCRegister(u8 Copy_u8Value);

void TIMER2_voidEnableOVFINT(void);
void TIMER2_voidDisableOVFINT(void);
void TIMER2_voidClearOVFFlag(void);


void TIMER2_voidEnableCTCINT(void);
void TIMER2_voidDisableCTCINT(void);
void TIMER2_voidClearCTCFlag(void);




void TIMER2_voidSetOVFCallBack(void (*Copy_pvoidCallBack) (void));
void TIMER2_voidSetCTCCallBack(void (*Copy_pvoidCallBack) (void));

void TIMER2_voidForceOutputCompare(void);


#endif /* MCAL_05__TIMER_TIMER_INTERFACE_H_ */
