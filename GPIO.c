/*
 * Main module configuring signal multiplexer for GPI0 Pins
 *
 * Author:
 * Created:
 * LJBeato
 * 2021
 */

#include "msp.h"
#include "uart.h"
#include "switches.h"
//#include "CortexM.h"
#include "Common.h"
/**
 * Waits for a delay (in milliseconds)
 *
 * del - The delay in milliseconds
 */
 int forward = 1;
void delay(int del) {
    volatile int i;
    for (i = 0; i < del * 50000; i++) {
        // Do nothing
    }
}

#define SW1 BIT1;
#define SW2 BIT4;


//void Switch1_Interrupt_Init(void) {
//    // disable interrupts
//    DisableInterrupts();
//    // initialize the Switch as per previous lab
//    Switch1_Init();



//    //7-0 PxIFG RW 0h Port X interrupt flag
//    //0b = No interrupt is pending.
//    //1b = Interrupt is pending.
//    // clear flag1 (reduce possibility of extra interrupt)
//    P1->IFG &= ~SW1;

//    //7-0 PxIE RW 0h Port X interrupt enable
//    //0b = Corresponding port interrupt disabled
//    //1b = Corresponding port interrupt enabled
//    // arm interrupt on  P1.1
//    P1->IE |= SW1;

//    //7-0 PxIES RW Undefined Port X interrupt edge select
//    //0b = PxIFG flag is set with a low-to-high transition.
//    //1b = PxIFG flag is set with a high-to-low transition
//    // now set the pin to cause falling edge interrupt event
//    // P1.1 is falling edge event
//    P1->IES |= SW1;


//    // now set the pin to cause falling edge interrupt event
//    NVIC_IPR8 = (NVIC_IPR8 & 0x00FFFFFF) | 0x40000000; // priority 2

//    // enable Port 1 - interrupt 35 in NVIC
//    NVIC_ISER1 |= 0x00000008;

//    // enable interrupts  (// clear the I bit	)
//    EnableInterrupts();

//}

//void PORT1_IRQHandler(void) {
//	char temp[78];
//    // First we check if it came from Switch1 ?
//    if (P1->IFG & BIT1)  // we start a timer to toggle the LED1 1 second ON and 1 second OFF
//    {
//        DisableInterrupts();
//        P1->IFG &= ~BIT1;
//        forward ^= forward;
//        EnableInterrupts();
//    }
//    // Now check to see if it came from Switch2 ?
//}

int main(void) {
    // Configure the Signal M ultiplexer for GPIO Pins
    // Configure the GPIO Pins for Output
    int phase = 0;
    
    //Switch1_Interrupt_Init();
    P4->SEL0 &= ~BIT1;
    P4->SEL1 &= ~BIT1;
    P4->SEL0 &= ~BIT2;
    P4->SEL1 &= ~BIT2;
    P4->SEL0 &= ~BIT3;
    P4->SEL1 &= ~BIT3;
    P4->SEL0 &= ~BIT4;
    P4->SEL1 &= ~BIT4;

    P4->DIR |= BIT1;
    P4->DIR |= BIT2;
    P4->DIR |= BIT3;
    P4->DIR |= BIT4;

    P4->DS |= BIT1;
    P4->DS |= BIT2;
    P4->DS |= BIT3;
    P4->DS |= BIT4;

    P4-> OUT &= ~BIT1;
    P4-> OUT &= ~BIT2;
    P4-> OUT &= ~BIT3;
    P4-> OUT &= ~BIT4;

    Switch1_Init();
    //EnableInterrupts();

    while (TRUE) {

        P4-> OUT &= ~BIT1;
        P4-> OUT &= ~BIT2;
        P4-> OUT &= ~BIT3;
        P4-> OUT &= ~BIT4;
        // Turn off all coils , Set GPIO pins to 0
        //Set one pin high at a time

        //Turn on an LED1 (RED) when button 1 is held
        //uart0_put("Hello");
		if (Switch1_Pressed() == TRUE) {
            // turn on LED1
            forward = 0;
        } else {
            
			forward = 1;
            // turn off LED1

        }
        if (forward) {
            if (phase == 0) {
                /*turn on coil A */

                P4-> OUT |= BIT1;


                //delay(1);
                phase++;


            } //A , 1a
            else if (phase == 1) {
                /*turn on coil B */
                P4-> OUT |= BIT2;
                //delay(10);
                phase++;
            } //B ,2a
            else if (phase == 2) {
                /*turn on coil C */
                P4-> OUT |= BIT3;

                //delay(10);
                phase++;
            } //C ,1b
            else {
                /*turn on coil D */
                P4-> OUT |= BIT4;
                //	delay(10);
                phase = 0;
				//forward = 0;
            } //D ,2b
        } else {// if it's reverse
            if (phase == 0) {
                /*turn on coil D */
                P4-> OUT |= BIT4;

                //delay(10);
                phase++;
            } //D ,2b

            else if (phase == 1) {
                /*turn on coil C */
                P4-> OUT |= BIT3;
        
                //delay(10);
                phase ++;
            } //C ,1 b
            else if (phase == 2) {
                /*turn on coil B */
               
                P4-> OUT |= BIT2;

                //delay(10);
                phase++;
            } //B ,2 a
            else {
                /*turn on coil A */
                P4-> OUT |= BIT1;

                phase = 0;
				//forward = 1;
            } //A ,1a

            //Note - you need to write your own delay function
        }
        delay(1); //s m aller values = faster speed


    }
}
