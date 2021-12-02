// Count increasing values from input
#include <stdio.h>

int main() {
	int c, number = 0, number_aux = 0;
	int increased_count = 0;

	while ( (c = getchar()) != EOF ) {
		// -48 to convert char to int.
		// + number*10 to shift the previous number to the left
		if (c != '\n') {
			number = c-48 + number*10;
		} else {
			if (number_aux != 0 && number_aux < number) {
				increased_count++;
			}

			// Save number as aux for the next loop and clear the number
			number_aux = number;
			number = 0;
		}
	}

	printf("%d\n", increased_count);
}
