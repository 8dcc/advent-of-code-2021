#include <stdio.h>

int main() {
	int c, check_first_char = 0, action = 0, action_value = 0;
	int aim = 0;
	int x_pos = 0, y_pos = 0;

	while ( (c = getchar()) != EOF ) {
		if (c != '\n') {
			if (check_first_char == 0) {  // First character of the line
				action = c;
				check_first_char = 1;
			} else if (c > 47 && c < 58) {
				action_value = c - 48;
			}
		} else {
			if (action == 'f') {
				x_pos = x_pos + action_value;
				y_pos = y_pos + aim * action_value;
			} else if (action == 'd') {
				aim = aim + action_value;  // Increase aim value
			} else if (action == 'u') {
				aim = aim - action_value;  // Decrease aim value
			}

			action = 0;
			action_value = 0;
			check_first_char = 0;
		}
	}

	printf("\n%d", x_pos * y_pos);
}
