/*
    CSC 230 Assignment 4
    Nov 25, 2015
    Michael Reiter
    V00831568
*/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define LED_DISABLED 0b00000000
#define LED_1 0b10000000
#define LED_2 0b00100000
#define LED_3 0b00001000
#define LED_4 0b00000010
#define LED_5 0b00001000
#define LED_6 0b00000010
#define DELAY 100


// Iteratively compute the nth Fibonacci number
int Fibon(int n) {
    int next = 0;
    int first = 0;
    int second = 1;

    for (int c = 0; c <= n; c++) {
        if (c <= 1) {
            next = c;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
    }
    return next;
}

void disableLED() {
	PORTL = LED_DISABLED;
	PORTB = LED_DISABLED;
}

void blink(int LED, int blinks) {
    // Set PORTL and PORTB for output
    DDRL = 0xFF;
    DDRB = 0xFF;

    // Select which LED to use
    int port_l_byte, port_b_byte;
    switch (LED) {
        case 0:
            port_l_byte = LED_1;
            port_b_byte = LED_DISABLED;
            break;
        case 1:
            port_l_byte = LED_2;
            port_b_byte = LED_DISABLED;
            break;
        case 2:
            port_l_byte = LED_3;
            port_b_byte = LED_DISABLED;
            break;
        case 3:
            port_l_byte = LED_4;
            port_b_byte = LED_DISABLED;
            break;
        case 4:
            port_l_byte = LED_DISABLED;
            port_b_byte = LED_5;
            break;
        case 5:
            port_l_byte = LED_DISABLED;
            port_b_byte = LED_6;
            break;
    }

    // Blink LED
    for (int i = 0; i < blinks; i++) {
        // Disable LED and delay briefly
		disableLED();
        _delay_ms(DELAY);

        // Enable LED and delay briefly
        PORTL = port_l_byte;
        PORTB = port_b_byte;
        _delay_ms(DELAY);
    }
}

int main() {
    // Since an integer is 16 bits in this architecture, the maximum value representing an 
    // integer using signed magnitude is 32767.
    // The maximum correct Fibonnaci value that can be stored in an integer is Fibon(23) = 1836311903.
    // Attempting to store values larger than this will cause an overflow.
    // For example, Fibon(24) = 46368 > 32767.

    // Arbitrarily blinking for the first 7 Fibonacci numbers. I chose a small number such as 7 since
    // the numbers grow very quickly. Fibon(7) = 13
    int n = 0;
    while (n < 7) {
        // Blink the (n modulus 6)th LED Fibon(n) times
        blink(n % 6, Fibon(n));
        n++;
    }
	disableLED();

    return 0;
}
