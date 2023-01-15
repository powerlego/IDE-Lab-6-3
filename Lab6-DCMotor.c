/*
 * Main module for testing the PWM Code for the K64F
 * 
 * Author:  
 * Created:  
 * Modified: Carson Clarke-Magrab <ctc7359@rit.edu> 
 * LJBeato
 * 2021
 */

#include "msp.h"
#include "uart.h"
#include "TimerA.h"
#include <stdio.h>


/**
 * Waits for a delay (in milliseconds)
 * 
 * del - The delay in milliseconds
 */
void delay(int del){
	volatile int i;
	for (i=0; i<del*50000; i++){
		;// Do nothing
	}
}

int main(void) {
	// Initialize UART and PWM
	// INSERT CODE HERE
	uart0_init();
	TIMER_A2_PWM_Init(SystemCoreClock/50/16,0,1);
	//TIMER_A0_PWM_Init(SystemCoreClock/10000,0,2);
	// Print welcome over serial
	uart0_put("Running... \n\r");
	
	// Part 1 - UNCOMMENT THIS
	// Generate 20% duty cycle at 10kHz
	// INSERT CODE HERE
	TIMER_A2_PWM_DutyCycle(0.075,1);
	delay(100);
	for(;;) {
//		for (int i=0; i<=50; i++) {
//			//sprintf(temp,"%f\r\n",(double)i/100);
//			//uart0_put(temp);
//		    TIMER_A2_PWM_DutyCycle((double)(0.05+(0.001*i)),1);
//			delay(10);
//		}
//		delay(100);
//		for (int i=0; i<=50; i++) {
//			//sprintf(temp,"%f\r\n",(double)i/100);
//			//uart0_put(temp);
//		    TIMER_A2_PWM_DutyCycle((double)(0.1-(0.001*i)),1);
//			delay(10);
//		}
	}		;  //then loop forever
	
	
	/* Part 2 - UNCOMMENT THIS
	*//*for(;;)  //loop forever
	{
		uint16_t dc = 0;
		uint16_t freq = 10000; // Frequency = 10 kHz 
		uint16_t dir = 0;
		char c = 48;
		int i=0;
		char temp [78]= {0};
		
		// 0 to 100% duty cycle in forward direction
		for (i=0; i<=100; i++) {
			//sprintf(temp,"%f\r\n",(double)i/100);
			//uart0_put(temp);
		    TIMER_A0_PWM_DutyCycle((double)i/100,1);
			TIMER_A0_PWM_DutyCycle(0,2);
			delay(10);
		}
		
		// 100% down to 0% duty cycle in the forward direction
		for (i=100; i>=0; i--) {
		    // INSERT CODE HERE
			TIMER_A0_PWM_DutyCycle((double)i/100,1);
			TIMER_A0_PWM_DutyCycle(0,2);
			delay(10);
		}
		
		// 0 to 100% duty cycle in reverse direction
		for (i=0; i<100; i++) {
			
		    // INSERT CODE HERE
			TIMER_A0_PWM_DutyCycle((double)i/100,2);
			TIMER_A0_PWM_DutyCycle(0,1);
			delay(10);
		}
		
		// 100% down to 0% duty cycle in the reverse direction
		for (i=100; i>=0; i--) {
		    // INSERT CODE HERE
			TIMER_A0_PWM_DutyCycle((double)i/100,2);
			TIMER_A0_PWM_DutyCycle(0,1);
			delay(10);
		}

	}*/
	return 0;
}



