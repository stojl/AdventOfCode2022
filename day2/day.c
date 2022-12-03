#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *f;
	f = fopen("input.txt", "r");

	char buff[4];

	int s = 0;
	while(fgets(buff, sizeof(buff), f) != NULL) {
		if(buff[0] == '\n') continue;
		char win, draw;
		switch(buff[2]) {
			case 'X':
				win = 'C';
				draw = 'A';
				s += 1;
				break;
			case 'Y':
				win = 'A';
				draw = 'B';
				s += 2;
				break;
			case 'Z':
				win = 'B';
				draw = 'C';
				s += 3;
				break;
		}

		if(buff[0] == win) {
			s += 6;
		} else if (buff[0] == draw) {
			s += 3;
		}
	}
	fclose(f);
	printf("%d\n", s);

	return 0;
}
