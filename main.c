/*
 * main.c
 */

#include <stdio.h>
#include <stdint.h>
#include <wiringPi.h>

typedef uint8_t byte_type;
typedef int     pin_type;

#ifndef P_0
#define P_0  8
#endif
#ifndef P_1
#define P_1  9
#endif
#ifndef P_2
#define P_2  7
#endif
#ifndef P_3
#define P_3 15
#endif
#ifndef P_4
#define P_4 16
#endif
#ifndef P_5
#define P_5  1
#endif
#ifndef P_6
#define P_6  0
#endif
#ifndef P_7
#define P_7  2
#endif
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
		if (wiringPiSetup() == -1)
			return 1;
		for (size_t k = 0; k < n_pins; ++k) {
			pinMode(pins[k], OUTPUT);
		}
	#endif
	return 0;
}

int readpin(pin_type pin) {
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
	printf("%d\n", byte);
	return 0;
}
