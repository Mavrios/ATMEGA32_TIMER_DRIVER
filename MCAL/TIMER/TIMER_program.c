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
#endif

#ifdef TIMER1_ENABLE
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
#endif

}
void TIMER_voidSetOVFRegister(u8 Copy_u8Timer , u16 Copy_u16Value){
	switch (Copy_u8Timer){
		case TIMER_u8_TIMER_0:
			TCNT0 = Copy_u16Value;
			break;
		/*
		case TIMER_u8_TIMER_1:
			TCNT0 = Copy_u16Value;
			break;
		case TIMER_u8_TIMER_2:
			TCNT0 = Copy_u16Value;
			break;
			*/
	}
}

void TIMER_voidSetCTCRegister(u8 Copy_u8Timer , u16 Copy_u16Value){
	switch (Copy_u8Timer){
		case TIMER_u8_TIMER_0:
			OCR0 = Copy_u16Value;
			break;
		/*
		case TIMER_u8_TIMER_1:
			OCR0 = Copy_u16Value;
			break;
		case TIMER_u8_TIMER_2:
			OCR0 = Copy_u16Value;
			break;
			*/
	}
}

void TIMER_voidEnableOVFINT(u8 Copy_u8Timer){
	switch (Copy_u8Timer){
		case TIMER_u8_TIMER_0:
			SET_BIT(TIMSK , TOIE0);
			break;
		/*
		case TIMER_u8_TIMER_1:
			SET_BIT(TIMSK , TOIE0);
			break;
		case TIMER_u8_TIMER_2:
			SET_BIT(TIMSK , TOIE0);
			break;
			*/
	}
}

void TIMER_voidDisableOVFINT(u8 Copy_u8Timer){
	switch (Copy_u8Timer){
		case TIMER_u8_TIMER_0:
			CLR_BIT(TIMSK , TOIE0);
			break;
		/*
		case TIMER_u8_TIMER_1:
			CLR_BIT(TIMSK , TOIE0);
			break;
		case TIMER_u8_TIMER_2:
			CLR_BIT(TIMSK , TOIE0);
			break;
			*/
	}
}

void TIMER_voidClearOVFFlag(u8 Copy_u8Timer){
	switch (Copy_u8Timer){
		case TIMER_u8_TIMER_0:
			SET_BIT(TIFR , TOV0);
			break;
		/*
		case TIMER_u8_TIMER_1:
			SET_BIT(TIFR , TOV0);
			break;
		case TIMER_u8_TIMER_2:
			SET_BIT(TIFR , TOV0);
			break;
			*/
	}
}


void TIMER_voidEnableCTCINT(u8 Copy_u8Timer){
	switch (Copy_u8Timer){
		case TIMER_u8_TIMER_0:
			SET_BIT(TIMSK , OCIE0);
			break;
		/*
		case TIMER_u8_TIMER_1:
			SET_BIT(TIMSK , TOIE0);
			break;
		case TIMER_u8_TIMER_2:
			SET_BIT(TIMSK , TOIE0);
			break;
			*/
	}
}


void TIMER_voidDisableCTCINT(u8 Copy_u8Timer){
	switch (Copy_u8Timer){
		case TIMER_u8_TIMER_0:
			CLR_BIT(TIMSK , OCIE0);
			break;
		/*
		case TIMER_u8_TIMER_1:
			CLR_BIT(TIMSK , TOIE0);
			break;
		case TIMER_u8_TIMER_2:
			CLR_BIT(TIMSK , TOIE0);
			break;
			*/
	}
}


void TIMER_voidClearCTCFlag(u8 Copy_u8Timer){
	switch (Copy_u8Timer){
		case TIMER_u8_TIMER_0:
			SET_BIT(TIFR , OCF0);
			break;
		/*
		case TIMER_u8_TIMER_1:
			SET_BIT(TIFR , OCF0);
			break;
		case TIMER_u8_TIMER_2:
			SET_BIT(TIFR , OCF0);
			break;
			*/
	}
}

void TIMER0_voidSetCTCCallBack(void (*Copy_pvoidCallBack) (void)){
	if(Copy_pvoidCallBack != NULL){
		TIMER_CTC_CallBack[TIMER_u8_TIMER_0] = Copy_pvoidCallBack;
	}

}


void TIMER0_voidSetOVFCallBack(void (*Copy_pvoidCallBack) (void)){
	if(Copy_pvoidCallBack != NULL){
		TIMER_OVF_CallBack[TIMER_u8_TIMER_0] = Copy_pvoidCallBack;
	}
}

void TIMER0_voidForceOutputCompare(void){
	SET_BIT(TCCR0,FOC0);
}


void __vector_11(void){
	TIMER_OVF_CallBack[TIMER_u8_TIMER_0]();
	TIMER_voidClearOVFFlag(TIMER_u8_TIMER_0);
}


void __vector_10(void){
	TIMER_CTC_CallBack[TIMER_u8_TIMER_0]();
	TIMER_voidClearCTCFlag(TIMER_u8_TIMER_0);
}


/*
//void TIMER_voidPostInit(const Timer_Configration *  Cpy_Configuration);






void TIMER_voidForceOutputCompare(u8 Copy_u8Timer);


*/


