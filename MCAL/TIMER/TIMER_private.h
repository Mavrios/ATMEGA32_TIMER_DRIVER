/*
 * Timer_private.h
 *
 *  Created on: Mar 20, 2021
 *      Author: Kishk
 */

#ifndef MCAL_05__TIMER_TIMER_PRIVATE_H_
#define MCAL_05__TIMER_TIMER_PRIVATE_H_

#define NULL 		0

void (*TIMER_OVF_CallBack[2])(void) = {NULL};
void (*TIMER_CTC_CallBack[2])(void) = {NULL};



/*					TIMER 0 REGISTERS						*/
#define TCCR0   (* (volatile u8 *) (0x53))
#define TCNT0   (* (volatile u8 *) (0x52))
#define OCR0    (* (volatile u8 *) (0x5C))
#define TIMSK   (* (volatile u8 *) (0x59))
#define TIFR    (* (volatile u8 *) (0x58))

#define FOC0	7
#define WGM00	6
#define COM01	5
#define COM00	4
#define WGM01	3
#define CS02	2
#define CS01	1
#define CS00	0


#define OCIE0	1
#define TOIE0	0

#define OCF0	1
#define TOV0	0

void __vector_11(void) __attribute__((signal));
void __vector_10(void) __attribute__((signal));

/*					TIMER 1 REGISTERS						*/





/*					TIMER 2 REGISTERS						*/

#define TCCR2   (* (volatile u8 *) (0x45))
#define TCNT2   (* (volatile u8 *) (0x44))
#define OCR2   (* (volatile u8 *) (0x43)







#endif /* MCAL_05__TIMER_TIMER_PRIVATE_H_ */
