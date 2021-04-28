/*
 * Timer_config.h
 *
 *  Created on: Mar 20, 2021
 *      Author: Kishk
 */

#ifndef MCAL_05__TIMER_TIMER_CONFIG_H_
#define MCAL_05__TIMER_TIMER_CONFIG_H_


/* 				TIMER 0 CONFIGURATION				*/

/*
 * 				UNCOMMENT TO ENABLE  TIMER 0
 * 				COMMENT   TO DISABLE TIMER 0
 */

#define TIMER0_ENABLE

/*
 * 				WAVEFORM GENERATION MODE
 *
 * OPTIONS:-
 * 			1-TIMER0_u8_NORMAL
 * 			2-TIMER0_u8_PWM_PHASE_CORRECT
 * 			3-TIMER0_u8_CTC
 * 			4-TIMER0_u8_FAST_PWM
 */

#define TIMER0_u8_WAVEFORM_MODE	TIMER0_u8_NORMAL

/*
 * 				OUTPUT MODE  OC0 (PORTB 3)
 *
 * OPTIONS (NON-PWM MODE):-
 * 			1-TIMER0_u8_OC0_DISCONNECTED
 * 			2-TIMER0_u8_OC0_TOGGLE
 * 			3-TIMER0_u8_OC0_CLEAR
 * 			4-TIMER0_u8_OC0_SET
 *
 * OPTIONS (FAST-PWM MODE):-
 * 			1-TIMER0_u8_OC0_DISCONNECTED
 * 			2-TIMER0_u8_OC0_CLEAR			(Clear OC0 on compare match, set OC0 at TOP)
 * 			3-TIMER0_u8_OC0_SET				(Set OC0 on compare match, clear OC0 at TOP)
 *
 * OPTIONS (PHASE-CORRECT-PWM MODE):-
 * 			1-TIMER0_u8_OC0_DISCONNECTED
 * 			2-TIMER0_u8_OC0_CLEAR			(Clear OC0 on compare match when up-counting. Set OC0 on comparematch when downcounting.)
 * 			3-TIMER0_u8_OC0_SET				(Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.)
 */


#define TIMER0_u8_OUTPUT_MODE	TIMER0_OC0_DISCONNECTED


/*
 * 				PRESCALLER
 *
 * OPTIONS:-
 * 			1-TIMER0_u8_STOP				(No clock source (Timer/Counter stopped).)
 * 			2-TIMER0_u8_DIV_BY_1
 * 			3-TIMER0_u8_DIV_BY_8
 * 			4-TIMER0_u8_DIV_BY_64
 * 			5-TIMER0_u8_DIV_BY_256
 * 			6-TIMER0_u8_DIV_BY_1024
 *
 */

#define TIMER0_u8_PRESCALLER	TIMER0_u8_DIV_BY_1


/*
 * 				INTERRUPT
 *
 * OPTIONS:-
 * 			1-TIMER0_u8_ENABLE_INTERRUPT
 * 			2-TIMER0_u8_DISABLE_INTERRUPT
 *
 */

#define TIMER0_u8_INTERRUPT		TIMER0_u8_DISABLE_INTERRUPT



/*----------------------------------------------------------------------------------------------------------------------------------*/




/* 				TIMER 1 CONFIGURATION				*/

/*
 * 				UNCOMMENT TO ENABLE  TIMER 1
 * 				COMMENT   TO DISABLE TIMER 1
 * 				UNCOMMENT TO ENABLE  TIMER 1 CHANNEL A
 * 				COMMENT   TO DISABLE TIMER 1 CHANNEL A
 * 				UNCOMMENT TO ENABLE  TIMER 1 CHANNEL B
 * 				COMMENT   TO DISABLE TIMER 1 CHANNEL B
 */

#define TIMER1_ENABLE
#define TIMER1_CHANNEL_A_ENABLE
#define TIMER1_CHANNEL_B_ENABLE




/*
 * 				WAVEFORM GENERATION MODE
 *
 * OPTIONS:-
 * 			1-TIMER1_u8_NORMAL
 * 			2-TIMER1_u8_PWM_PHASE_CORRECT_8BIT
 * 			3-TIMER1_u8_PWM_PHASE_CORRECT_9BIT
 * 			4-TIMER1_u8_PWM_PHASE_CORRECT_10BIT
 * 			5-TIMER1_u8_CTC_OCR1A
 * 			6-TIMER1_u8_FAST_PWM_8BIT
 * 			7-TIMER1_u8_FAST_PWM_9BIT
 * 			8-TIMER1_u8_FAST_PWM_10BIT
 * 			9-TIMER1_u8_PWM_PHASE_FREQUANCY_CORRECT_ICR1
 * 			10-TIMER1_u8_PWM_PHASE_FREQUANCY_CORRECT_OCR1A
 * 			11-TIMER1_u8_PWM_PHASE_CORRECT_ICR1
 * 			12-TIMER1_u8_PWM_PHASE_CORRECT_OCR1A
 * 			13-TIMER1_u8_CTC_ICR1
 * 			14-TIMER1_u8_FAST_PWM_ICR1
 * 			15-TIMER1_u8_FAST_PWM_OCR1A
 */

#define TIMER1_u8_CHANNEL_A_WAVEFORM_MODE	TIMER1_u8_NORMAL
#define TIMER1_u8_CHANNEL_B_WAVEFORM_MODE	TIMER1_u8_NORMAL




/*
 * 				OUTPUT MODE  OC0 (PORTB 3)
 *
 * OPTIONS (NON-PWM MODE):-
 * 			1-TIMER1_u8_OC1_DISCONNECTED	(Normal port operation, OC1A/OC1B disconnected)
 * 			2-TIMER1_u8_OC1_TOGGLE			(Toggle OC1A/OC1B on compare match)
 * 			3-TIMER1_u8_OC1_CLEAR			(Clear OC1A/OC1B on compare match (Set output to low level))
 * 			4-TIMER1_u8_OC1_SET				(Set OC1A/OC1B on compare match (Set output to high level))
 *
 * OPTIONS (FAST-PWM MODE):-
 * 			1-TIMER1_u8_OC0_DISCONNECTED	(Normal port operation, OC1A/OC1B disconnected)
 * 	 		2-TIMER1_u8_OC1_TOGGLE			(WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation). For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.)
 * 			2-TIMER1_u8_OC1_CLEAR			(Clear OC1A/OC1B on compare match, set OC1A/OC1B at TOP)
 * 			3-TIMER1_u8_OC1_SET				(Set OC1A/OC1B on compare match, clear OC1A/OC1B at TOP)
 *
 * OPTIONS (Phase Correct and Phase and Frequency Correct PWM):-
 * 			1-TIMER1_u8_OC1_DISCONNECTED	(Normal port operation, OC1A/OC1B disconnected)
 * 	 		2-TIMER1_u8_OC1_TOGGLE			(WGM13:0 = 9 or 14: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation). For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.)
 * 			2-TIMER1_u8_OC1_CLEAR			(Clear OC1A/OC1B on compare match when up-counting. Set OC1A/OC1B on compare match when downcounting.)
 * 			3-TIMER1_u8_OC1_SET				(Set OC1A/OC1B on compare match when upcounting. Clear OC1A/OC1B on compare match when downcounting.)
 *
 */


#define TIMER1_u8_CHANNEL_A_OUTPUT_MODE	TIMER1_OC1_DISCONNECTED
#define TIMER1_u8_CHANNEL_B_OUTPUT_MODE	TIMER1_OC1_DISCONNECTED


/*
 * 				PRESCALLER
 *
 * OPTIONS:-
 * 			1-TIMER1_u8_STOP				(No clock source (Timer/Counter stopped).)
 * 			2-TIMER1_u8_DIV_BY_1
 * 			3-TIMER1_u8_DIV_BY_8
 * 			4-TIMER1_u8_DIV_BY_64
 * 			5-TIMER1_u8_DIV_BY_256
 * 			6-TIMER1_u8_DIV_BY_1024
 *
 */

#define TIMER1_u8_PRESCALLER	TIMER1_u8_DIV_BY_1


/*
 * 				INPUT CAPTURE EDGE SELECT
 *
 * OPTIONS:-
 * 			1-TIMER1_u8_FALLING_INPUT_CAPTURE
 * 			2-TIMER1_u8_RISING_INPUT_CAPTURE
 *
 */


#define TIMER1_u8_INPUT_CAPTURE	TIMER1_u8_FALLING_INPUT_CAPTURE

/*----------------------------------------------------------------------------------------------------------------------------------*/

/* 				TIMER 2 CONFIGURATION				*/

/*
 * 				UNCOMMENT TO ENABLE  TIMER 2
 * 				COMMENT   TO DISABLE TIMER 2
 */

#define TIMER2_ENABLE

/*
 * 				WAVEFORM GENERATION MODE
 *
 * OPTIONS:-
 * 			1-TIMER2_u8_NORMAL
 * 			2-TIMER2_u8_PWM_PHASE_CORRECT
 * 			3-TIMER2_u8_CTC
 * 			4-TIMER2_u8_FAST_PWM
 */

#define TIMER2_u8_WAVEFORM_MODE	TIMER2_u8_NORMAL

/*
 * 				OUTPUT MODE  OC2 (PORTD 7)
 *
 * OPTIONS (NON-PWM MODE):-
 * 			1-TIMER2_u8_OC2_DISCONNECTED
 * 			2-TIMER2_u8_OC2_TOGGLE
 * 			3-TIMER2_u8_OC2_CLEAR
 * 			4-TIMER2_u8_OC2_SET
 *
 * OPTIONS (FAST-PWM MODE):-
 * 			1-TIMER2_u8_OC2_DISCONNECTED
 * 			2-TIMER2_u8_OC2_CLEAR			(Clear OC2 on compare match, set OC2 at TOP)
 * 			3-TIMER2_u8_OC2_SET				(Set OC2 on compare match, clear OC2 at TOP)
 *
 * OPTIONS (PHASE-CORRECT-PWM MODE):-
 * 			1-TIMER2_u8_OC2_DISCONNECTED
 * 			2-TIMER2_u8_OC2_CLEAR			(Clear OC2 on compare match when up-counting. Set OC2 on comparematch when downcounting.)
 * 			3-TIMER2_u8_OC2_SET				(Set OC2 on compare match when up-counting. Clear OC2 on compare match when downcounting.)
 */


#define TIMER2_u8_OUTPUT_MODE	TIMER2_OC2_DISCONNECTED


/*
 * 				PRESCALLER
 *
 * OPTIONS:-
 * 			1-TIMER2_u8_STOP				(No clock source (Timer/Counter stopped).)
 * 			2-TIMER2_u8_DIV_BY_1
 * 			3-TIMER2_u8_DIV_BY_8
 * 			4-TIMER2_u8_DIV_BY_32
 * 			5-TIMER2_u8_DIV_BY_64
 * 			6-TIMER2_u8_DIV_BY_128
 * 			7-TIMER2_u8_DIV_BY_256
 * 			8-TIMER2_u8_DIV_BY_1024
 *
 */

#define TIMER2_u8_PRESCALLER	TIMER2_u8_DIV_BY_1


/*
 * 				INTERRUPT
 *
 * OPTIONS:-
 * 			1-TIMER2_u8_ENABLE_INTERRUPT
 * 			2-TIMER2_u8_DISABLE_INTERRUPT
 *
 */

#define TIMER2_u8_INTERRUPT		TIMER2_u8_DISABLE_INTERRUPT




#endif /* MCAL_05__TIMER_TIMER_CONFIG_H_ */
