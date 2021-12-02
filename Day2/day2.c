#include <stdio.h>

#define MAX_LINE_LEN 20

int main() {
	int c, check_first_char = 0, action = 0, action_value = 0;
	int x_pos = 0, y_pos = 0;

	while ( (c = getchar()) != EOF ) {
		if (c != '\n') {
			if (check_first_char == 0) {
				action = c;
				check_first_char = 1;
			} else if (c > 47 && c < 58) {  // c is a digit
				action_value = c - 48;
			}
		} else {
			if (action == 'f') {
				x_pos = x_pos + action_value;
			} else if (action == 'd') {
				y_pos = y_pos + action_value;  // Increase depth
			} else if (action == 'u') {
				y_pos = y_pos - action_value;
			}

			action = 0;
			action_value = 0;
			check_first_char = 0;
		}
	}

	printf("\n%d", x_pos * y_pos);
}
