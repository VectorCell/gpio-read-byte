/*
 * main.c
 */

//#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <wiringPi.h>

typedef uint8_t byte_type;
typedef int     pin_type;

#define P_0  8
#define P_1  9
#define P_2  7
#define P_3 15
#define P_4 16
#define P_5  1
#define P_6  0
#define P_7  2
const size_t n_pins = 8;
const pin_type pins[] = {
	P_0,
	P_1,
	P_2,
	P_3,
	P_4,
	P_5,
	P_6,
	P_7
};

int init () {
	#ifndef DEBUG
		return wiringPiSetup();
	#else
		return 0;
	#endif
}

int readpin(pin pin) {
	#ifndef DEBUG
		return digitalRead(pin);
	#else
		return 1;
	#endif
}

int main (int argc, char *argv[]) {
	if (init() == -1) {
		printf("ERROR: unable to access gpio pins\n");
		return 1;
	}
	byte_type byte = 0;
	for (size_t k = 0; k < n_pins; ++k) {
		byte <<= 1;
		byte += readpin(pins[k]);
	}
	printf("byte is: %d\n", byte);
	return 0;
}
