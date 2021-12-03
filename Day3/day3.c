#include <stdio.h>

#define ARRAY_LEN 12

int array_to_digit(int array[]);
int array_to_binary(int array[]);
int power(int value, int power);

int main() {
	int c, line_counter = 0, line_pos = 0;
	int frecuent_array[ARRAY_LEN], unfrecuent_array[ARRAY_LEN];
	int gamma_rate, epsilon_rate;
	
	// Clear the array
	for (int n = 0; n < ARRAY_LEN; n++) {
		frecuent_array[n] = 0;
	}

	// Read from file
	while ( (c = getchar()) != EOF ) {
		// Each character of the line
		if (c != '\n') {
			frecuent_array[line_pos] = frecuent_array[line_pos] + c-48;  // Count the ones
			line_pos++;
		} else {
			line_pos = 0;
			line_counter++;
		}
	}

	// Based on the lines and 1s, check the most frequent
	for (int n = 0; n < ARRAY_LEN; n++) {
		if ( frecuent_array[n] > (line_counter/2) ) {
			frecuent_array[n] = 1;
			unfrecuent_array[n] = 0;
		} else {
			frecuent_array[n] = 0;
			unfrecuent_array[n] = 1;
		}
	}

	gamma_rate = array_to_binary(frecuent_array);
	epsilon_rate = array_to_binary(unfrecuent_array);
	printf("%d * %d = %d\n", gamma_rate, epsilon_rate, gamma_rate*epsilon_rate);
}

int array_to_digit(int array[]) {
	int digit = 0;

	for (int n = 0; n < ARRAY_LEN; n++) {
		digit = digit*10 + array[n];
	}

	return digit;
}

int array_to_binary(int array[]) {
	int digit = 0, pos = 0;

	// Start from the end
	for (int n = ARRAY_LEN - 1; n >= 0; n--) {
		digit = digit + ( array[n] * power(2, pos));
		pos++;
	}

	return digit;
}

int power(int value, int power) {
	int output = 1;
	for (int n = 0; n < power; n++) {
		output = output * value;
	}
	return output;
}
