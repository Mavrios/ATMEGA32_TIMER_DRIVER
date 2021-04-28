/*
 * Timer_program.c
 *
 *  Created on: Mar 20, 2021
 *      Author: Kishk
 */

#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATHS.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"


void TIMER_voidInit(void){

	/*										TIMER0											*/

#ifdef TIMER0_ENABLE
	#if TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_NORMAL
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	#elif TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_PWM_PHASE_CORRECT
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	#elif TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_CTC
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	#elif TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_FAST_PWM
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	#endif

	#if	TIMER0_u8_OUTPUT_MODE == TIMER0_OC0_DISCONNECTED
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	#elif TIMER0_u8_OUTPUT_MODE == TIMER0_u8_OC0_TOGGLE
		#if	TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_PWM_PHASE_CORRECT || TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_FAST_PWM
		#warning ("CHOOSED UNAVAILABLE OPTION IN TIMER OUTPUT MODE!!")
		#else
			SET_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		#endif
	#elif TIMER0_u8_OUTPUT_MODE == TIMER0_u8_OC0_CLEAR
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#elif TIMER0_u8_OUTPUT_MODE == TIMER0_u8_OC0_SET
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	#endif

	#if TIMER0_u8_PRESCALLER == TIMER0_u8_STOP
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	#elif TIMER0_u8_PRESCALLER == TIMER0_u8_DIV_BY_1
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	#elif TIMER0_u8_PRESCALLER == TIMER0_u8_DIV_BY_8
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	#elif TIMER0_u8_PRESCALLER == TIMER0_u8_DIV_BY_64
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	#elif TIMER0_u8_PRESCALLER == TIMER0_u8_DIV_BY_256
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	#elif TIMER0_u8_PRESCALLER == TIMER0_u8_DIV_BY_1024
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	#endif

	#if TIMER0_u8_INTERRUPT == TIMER0_u8_ENABLE_INTERRUPT
		#if TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_NORMAL
			SET_BIT(TIMSK,TOIE0);
		#elif TIMER0_u8_WAVEFORM_MODE == TIMER0_u8_CTC
			SET_BIT(TIMSK,OCIE0);
		#endif

	#endif
#endif


		/*										TIMER1											*/

#ifdef TIMER1_ENABLE
	#if TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_NORMAL
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_PWM_PHASE_CORRECT_8BIT
		SET_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_PWM_PHASE_CORRECT_9BIT
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_PWM_PHASE_CORRECT_10BIT
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_CTC_OCR1A
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_FAST_PWM_8BIT
		SET_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_FAST_PWM_9BIT
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_FAST_PWM_10BIT
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_PWM_PHASE_FREQUANCY_CORRECT_ICR1
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_PWM_PHASE_FREQUANCY_CORRECT_OCR1A
		SET_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_PWM_PHASE_CORRECT_ICR1
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_PWM_PHASE_CORRECT_OCR1A
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_CTC_ICR1
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_FAST_PWM_ICR1
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_u8_WAVEFORM_MODE == TIMER1_u8_FAST_PWM_OCR1A
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#endif

	#ifdef TIMER1_CHANNEL_A_ENABLE
		#if	TIMER1_u8_OUTPUT_MODE == TIMER1_OC1_DISCONNECTED
			CLR_BIT(TCCR1A,COM1A0);
			CLR_BIT(TCCR1A,COM1A1);
		#elif TIMER1_u8_OUTPUT_MODE == TIMER1_u8_OC1_TOGGLE
			SET_BIT(TCCR1A,COM1A0);
			CLR_BIT(TCCR1A,COM1A1);
		#elif TIMER1_u8_OUTPUT_MODE == TIMER1_u8_OC1_CLEAR
			CLR_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
		#elif TIMER1_u8_OUTPUT_MODE == TIMER1_u8_OC1_SET
			SET_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
		#endif
	#endif

	#ifdef TIMER1_CHANNEL_B_ENABLE
		#if	TIMER1_u8_OUTPUT_MODE == TIMER1_OC1_DISCONNECTED
			CLR_BIT(TCCR1A,COM1B0);
			CLR_BIT(TCCR1A,COM1B1);
		#elif TIMER1_u8_OUTPUT_MODE == TIMER1_u8_OC1_TOGGLE
			SET_BIT(TCCR1A,COM1B0);
			CLR_BIT(TCCR1A,COM1B1);
		#elif TIMER1_u8_OUTPUT_MODE == TIMER1_u8_OC1_CLEAR
			CLR_BIT(TCCR1A,COM1B0);
			SET_BIT(TCCR1A,COM1B1);
		#elif TIMER1_u8_OUTPUT_MODE == TIMER1_u8_OC1_SET
			SET_BIT(TCCR1A,COM1B0);
			SET_BIT(TCCR1A,COM1B1);
		#endif
	#endif

	#if TIMER1_u8_PRESCALLER == TIMER1_u8_STOP
		CLR_BIT(TCCR1B,CS10);
		CLR_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
	#elif TIMER1_u8_PRESCALLER == TIMER1_u8_DIV_BY_1
		SET_BIT(TCCR1B,CS10);
		CLR_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
	#elif TIMER1_u8_PRESCALLER == TIMER1_u8_DIV_BY_8
		CLR_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
	#elif TIMER1_u8_PRESCALLER == TIMER1_u8_DIV_BY_64
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS12);
	#elif TIMER1_u8_PRESCALLER == TIMER1_u8_DIV_BY_256
		CLR_BIT(TCCR1B,CS10);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
	#elif TIMER1_u8_PRESCALLER == TIMER1_u8_DIV_BY_1024
		SET_BIT(TCCR1B,CS10);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
	#endif

	#if TIMER1_u8_INPUT_CAPTURE == TIMER1_u8_RISING_INPUT_CAPTURE
		SET_BIT(TCCR1B,ICES1);
	#elif TIMER1_u8_INPUT_CAPTURE == TIMER1_u8_FALLING_INPUT_CAPTURE
		CLR_BIT(TCCR1B,ICES1);
	#endif
#endif

		/*										TIMER2											*/

	#ifdef TIMER2_ENABLE
		#if TIMER2_u8_WAVEFORM_MODE == TIMER2_u8_NORMAL
			CLR_BIT(TCCR2,WGM20);
			CLR_BIT(TCCR2,WGM21);
		#elif TIMER2_u8_WAVEFORM_MODE == TIMER2_u8_PWM_PHASE_CORRECT
			SET_BIT(TCCR2,WGM20);
			CLR_BIT(TCCR2,WGM21);
		#elif TIMER2_u8_WAVEFORM_MODE == TIMER2_u8_CTC
			CLR_BIT(TCCR2,WGM20);
			SET_BIT(TCCR2,WGM21);
		#elif TIMER2_u8_WAVEFORM_MODE == TIMER2_u8_FAST_PWM
			SET_BIT(TCCR2,WGM20);
			SET_BIT(TCCR2,WGM21);
		#endif

		#if	TIMER2_u8_OUTPUT_MODE == TIMER2_OC2_DISCONNECTED
			CLR_BIT(TCCR2,COM20);
			CLR_BIT(TCCR2,COM21);
		#elif TIMER2_u8_OUTPUT_MODE == TIMER2_u8_OC2_TOGGLE
			#if	TIMER2_u8_WAVEFORM_MODE == TIMER2_u8_PWM_PHASE_CORRECT || TIMER2_u8_WAVEFORM_MODE == TIMER2_u8_FAST_PWM
			#warning ("CHOOSED UNAVAILABLE OPTION IN TIMER OUTPUT MODE!!")
			#else
				SET_BIT(TCCR2,COM20);
				CLR_BIT(TCCR2,COM21);
			#endif
		#elif TIMER2_u8_OUTPUT_MODE == TIMER2_u8_OC2_CLEAR
			CLR_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
		#elif TIMER2_u8_OUTPUT_MODE == TIMER2_u8_OC2_SET
			SET_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
		#endif

		#if TIMER2_u8_PRESCALLER == TIMER2_u8_STOP
			CLR_BIT(TCCR2,CS20);
			CLR_BIT(TCCR2,CS21);
			CLR_BIT(TCCR2,CS22);
		#elif TIMER2_u8_PRESCALLER == TIMER2_u8_DIV_BY_1
			SET_BIT(TCCR2,CS20);
			CLR_BIT(TCCR2,CS21);
			CLR_BIT(TCCR2,CS22);
		#elif TIMER2_u8_PRESCALLER == TIMER2_u8_DIV_BY_8
			CLR_BIT(TCCR2,CS20);
			SET_BIT(TCCR2,CS21);
			CLR_BIT(TCCR2,CS22);
		#elif TIMER2_u8_PRESCALLER == TIMER2_u8_DIV_BY_32
			SET_BIT(TCCR2,CS20);
			SET_BIT(TCCR2,CS21);
			CLR_BIT(TCCR2,CS22);
		#elif TIMER2_u8_PRESCALLER == TIMER2_u8_DIV_BY_64
			CLR_BIT(TCCR2,CS20);
			CLR_BIT(TCCR2,CS21);
			SET_BIT(TCCR2,CS22);
		#elif TIMER2_u8_PRESCALLER == TIMER2_u8_DIV_BY_128
			SET_BIT(TCCR2,CS20);
			CLR_BIT(TCCR2,CS21);
			SET_BIT(TCCR2,CS22);
		#elif TIMER2_u8_PRESCALLER == TIMER2_u8_DIV_BY_256
			CLR_BIT(TCCR2,CS20);
			SET_BIT(TCCR2,CS21);
			SET_BIT(TCCR2,CS22);
		#elif TIMER2_u8_PRESCALLER == TIMER2_u8_DIV_BY_1024
			SET_BIT(TCCR2,CS20);
			SET_BIT(TCCR2,CS21);
			SET_BIT(TCCR2,CS22);
		#endif

		#if TIMER2_u8_INTERRUPT == TIMER2_u8_ENABLE_INTERRUPT
			#if TIMER2_u8_WAVEFORM_MODE == TIMER2_u8_NORMAL
				SET_BIT(TIMSK,TOIE2);
			#elif TIMER2_u8_WAVEFORM_MODE == TIMER2_u8_CTC
				SET_BIT(TIMSK,OCIE2);
			#endif

		#endif
	#endif

}

/*										TIMER0											*/

void TIMER0_voidSetOVFRegister(u8 Copy_u8Value){
			TCNT0 = Copy_u8Value;
}

void TIMER0_voidSetCTCRegister(u8 Copy_u8Value){
			OCR0 = Copy_u8Value;
}

void TIMER0_voidEnableOVFINT(void){
	SET_BIT(TIMSK , TOIE0);

}

void TIMER0_voidDisableOVFINT(void){
	CLR_BIT(TIMSK , TOIE0);
}

void TIMER0_voidClearOVFFlag(void){
	SET_BIT(TIFR , TOV0);

}


void TIMER0_voidEnableCTCINT(void){
	SET_BIT(TIMSK , OCIE0);
}


void TIMER0_voidDisableCTCINT(void){
	CLR_BIT(TIMSK , OCIE0);
}


void TIMER0_voidClearCTCFlag(void){
	SET_BIT(TIFR , OCF0);
}

void TIMER0_voidSetCTCCallBack(void (*Copy_pvoidCallBack) (void)){
	if(Copy_pvoidCallBack != NULL){
		TIMER_CallBack[TIMER0_CTC_CALLBACK_INDEX] = Copy_pvoidCallBack;
	}

}


void TIMER0_voidSetOVFCallBack(void (*Copy_pvoidCallBack) (void)){
	if(Copy_pvoidCallBack != NULL){
		TIMER_CallBack[TIMER0_OVF_CALLBACK_INDEX] = Copy_pvoidCallBack;
	}
}

void TIMER0_voidForceOutputCompare(void){
	SET_BIT(TCCR0,FOC0);
}


void __vector_11(void){
	TIMER_CallBack[TIMER0_OVF_CALLBACK_INDEX]();
	TIMER0_voidClearOVFFlag();
}


void __vector_10(void){
	TIMER_CallBack[TIMER0_CTC_CALLBACK_INDEX]();
	TIMER0_voidClearCTCFlag();
}



/*										TIMER1											*/


void TIMER1_voidSetOVFRegister(u16 Copy_u16Value){
	TCNT1 = Copy_u16Value;
}


void TIMER1_voidChannelASetCTCRegister(u16 Copy_u16Value){
	OCR1A	= Copy_u16Value;
}

void TIMER1_voidChannelBSetCTCRegister(u16 Copy_u16Value){
	OCR1B	= Copy_u16Value;

}

u16 TIMER1_u16InputCaptureValue(void){
	return ICR1;
}

void TIMER1_voidEnableOVFINT(void){
	SET_BIT(TIMSK,TOIE1);
}

void TIMER1_voidDisableOVFINT(void){
	CLR_BIT(TIMSK,TOIE1);
}

void TIMER1_voidClearOVFFlag(void){
	SET_BIT(TIFR,TOV1);
}

void TIMER1_voidChannelAEnableCTCINT(void){
	SET_BIT(TIMSK,OCIE1A);
}

void TIMER1_voidChannelADisableCTCINT(void){
	CLR_BIT(TIMSK,OCIE1A);
}

void TIMER1_voidChannelAClearCTCFlag(void){
	SET_BIT(TIFR,OCF1A);
}

void TIMER1_voidChannelBEnableCTCINT(void){
	SET_BIT(TIMSK,OCIE1B);
}

void TIMER1_voidChannelBDisableCTCINT(void){
	CLR_BIT(TIMSK,OCIE1B);
}

void TIMER1_voidChannelBClearCTCFlag(void){
	SET_BIT(TIFR,OCF1B);
}

void TIMER1_voidEnableInputCaptureINT(void){
	SET_BIT(TIMSK,TICIE1);
}

void TIMER1_voidDisableInputCaptureINT(void){
	CLR_BIT(TIMSK,TICIE1);
}

void TIMER1_voidClearInputCaptureFlag(void){
	SET_BIT(TIFR,ICF1);
}

void TIMER1_voidSetOVFCallBack(void (*Copy_pvoidCallBack) (void)){
	TIMER_CallBack[TIMER1_OVF_CALLBACK_INDEX]=Copy_pvoidCallBack;
}

void TIMER1_voidChannelASetCTCCallBack(void (*Copy_pvoidCallBack) (void)){
	TIMER_CallBack[TIMER1_CTC_CHANNEL_A_CALLBACK_INDEX]=Copy_pvoidCallBack;
}


void TIMER1_voidChannelBSetCTCCallBack(void (*Copy_pvoidCallBack) (void)){
	TIMER_CallBack[TIMER1_CTC_CHANNEL_B_CALLBACK_INDEX]=Copy_pvoidCallBack;
}

void TIMER1_voidSetInputCaptureCallBack(void (*Copy_pvoidCallBack) (void)){
	TIMER_CallBack[TIMER1_INPUT_CAPTURE_CALLBACK_INDEX]=Copy_pvoidCallBack;
}

void TIMER1_voidChannelAForceOutputCompare(void){
	SET_BIT(TCCR1A,FOC1A);
}

void TIMER1_voidChannelBForceOutputCompare(void){
	SET_BIT(TCCR1A,FOC1B);
}


void __vector_6(void){
	TIMER_CallBack[TIMER1_INPUT_CAPTURE_CALLBACK_INDEX]();
	TIMER1_voidClearInputCaptureFlag();
}

void __vector_7(void){
	TIMER_CallBack[TIMER1_CTC_CHANNEL_A_CALLBACK_INDEX]();
	TIMER1_voidChannelAClearCTCFlag();
}

void __vector_8(void){
	TIMER_CallBack[TIMER1_CTC_CHANNEL_B_CALLBACK_INDEX]();
	TIMER1_voidChannelBClearCTCFlag();
}

void __vector_9(void){
	TIMER_CallBack[TIMER1_OVF_CALLBACK_INDEX]();
	TIMER1_voidClearOVFFlag();
}



/*										TIMER2											*/

void TIMER2_voidSetOVFRegister(u8 Copy_u8Value){
	TCNT2 = Copy_u8Value;
}

void TIMER2_voidSetCTCRegister(u8 Copy_u8Value){
	OCR2 = Copy_u8Value;
}

void TIMER2_voidEnableOVFINT(void){
	SET_BIT(TIMSK , TOIE2);

}

void TIMER2_voidDisableOVFINT(void){
	CLR_BIT(TIMSK , TOIE2);
}

void TIMER2_voidClearOVFFlag(void){
	SET_BIT(TIFR , TOV2);

}


void TIMER2_voidEnableCTCINT(void){
	SET_BIT(TIMSK , OCIE2);
}


void TIMER2_voidDisableCTCINT(void){
	CLR_BIT(TIMSK , OCIE2);
}


void TIMER2_voidClearCTCFlag(void){
	SET_BIT(TIFR , OCF2);
}

void TIMER2_voidSetCTCCallBack(void (*Copy_pvoidCallBack) (void)){
	if(Copy_pvoidCallBack != NULL){
		TIMER_CallBack[TIMER2_CTC_CALLBACK_INDEX] = Copy_pvoidCallBack;
	}

}


void TIMER2_voidSetOVFCallBack(void (*Copy_pvoidCallBack) (void)){
	if(Copy_pvoidCallBack != NULL){
		TIMER_CallBack[TIMER2_OVF_CALLBACK_INDEX] = Copy_pvoidCallBack;
	}
}

void TIMER2_voidForceOutputCompare(void){
	SET_BIT(TCCR2,FOC2);
}


void __vector_5(void){
	TIMER_CallBack[TIMER2_OVF_CALLBACK_INDEX]();
	TIMER2_voidClearOVFFlag();
}


void __vector_4(void){
	TIMER_CallBack[TIMER2_CTC_CALLBACK_INDEX]();
	TIMER2_voidClearCTCFlag();
}



/*
//void TIMER_voidPostInit(const Timer_Configration *  Cpy_Configuration);

*/



