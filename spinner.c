/*
 * File:   spinner.c
 * Author: jvezz
 *
 * Created on March 1, 2025, 12:52 PM
 */

// CONFIG
#pragma config OSC = RC         // Oscillator selection bits (RC oscillator)
#pragma config WDT = OFF         // Watchdog timer enable bit (WDT enabled)
#pragma config CP = OFF         // Code protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

// Macros to make it easier to identify LED lights
// PORT A
#define A_BOTTOM_RIGHT (0x1 << 0)
#define A_LOWER_RIGHT (0x1 << 1)
#define A_RIGHT (0x1 << 2)
#define A_UPPER_RIGHT (0x1 << 3)

// PORT B
#define B_TOP_RIGHT (0x1 << 0)
#define B_TOP_LEFT (0x1 << 1)
#define B_UPPER_LEFT (0x1 << 2)
#define B_LEFT (0x1 << 3)
#define B_LOWER_LEFT (0x1 << 4)
#define B_BOTTOM_LEFT (0x1 << 5)

unsigned short i = 0;
unsigned short delay_i = 0;

// Nice array for my sanity
const unsigned short pinArray[] =   {B_TOP_RIGHT, 
                                    A_UPPER_RIGHT, 
                                    A_RIGHT,
                                    A_LOWER_RIGHT,
                                    A_BOTTOM_RIGHT,
                                    B_TOP_LEFT,
                                    B_UPPER_LEFT,
                                    B_LEFT,
                                    B_LOWER_LEFT,
                                    B_BOTTOM_LEFT };

void init(void) {
    // Set all PORTA pins as output 
    TRISA = 0x0;
    // Set all PORTB pins as output
    TRISB = 0x00;
    
    // Reset all
    PORTA = 0x0;
    PORTB = 0x0;
    
    return;
}

// Turn on the pin specified by index
void set(unsigned short index) {
    if(index > 0 && index < 5)
        PORTA |= pinArray[index];
    else
        PORTB |= pinArray[index];
}

// Turn off all lights
void reset() {
    PORTA = 0x0;
    PORTB = 0x0;
}

void delay(unsigned int ticks) {
    for (delay_i=0; delay_i < ticks; delay_i++);
    
    return;
}

void flash(unsigned int count, unsigned int ticks) {
    for (i=0; i < count; i++) {
        PORTA = 0xf;
        PORTB = 0xff;
        delay(ticks);
        PORTA = 0x0;
        PORTB = 0x0;
        delay(ticks);
    }

}

// Spin a light that slows down around the badge
// then flash a couple times.
void main(void) {
    
    init();
    
    unsigned short d;
    while(1){
        
        d = 1;
        while(d < 30){
            //Shine a light during delay
            set(i);
            delay(d * 50);
            reset();
            
            d++; //Increase delay
            
            //Increase light index
            i++;
            i %= 10; //Only 10 lights, 0-9
        }
        
        flash(3, 2000);
    }
    
    // Should never reach
    return;
}
