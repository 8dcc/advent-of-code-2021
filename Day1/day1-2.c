// Count increasing values from input
#include <stdio.h>

int main() {
	int c, number = 0, array_sum = 0, array_sum_aux = 0;
	int compare_me[3] = {0, 0, 0};
	int increased_count = 0;

	while ( (c = getchar()) != EOF ) {
		// -48 to convert char to int.
		// + number*10 to shift the previous number to the left
		if (c != '\n') {
			number = c-48 + number*10;
		} else {
			// Shift the array
			compare_me[0] = compare_me[1];
			compare_me[1] = compare_me[2];
			compare_me[2] = number;

			// Sum the array if it is filled
			if (compare_me[0] != 0 && compare_me[1] != 0 && compare_me[2] != 0 ) {
				array_sum = compare_me[0] + compare_me[1] + compare_me[2];
			}
			
			// Increase the result
			if (array_sum_aux != 0 && array_sum_aux < array_sum) {
				increased_count++;
			}

			array_sum_aux = array_sum;
			number = 0;
		}
	}

	printf("%d\n", increased_count);
}
