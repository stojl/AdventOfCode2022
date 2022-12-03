#include <stdio.h>
#include <stdlib.h>

int main() {
        FILE *f;
        f = fopen("input.txt", "r");

        char buff[4];

        int s = 0;
        while(fgets(buff, sizeof(buff), f) != NULL) {
                if(buff[0] == '\n') continue;
		int win, draw, loss;
		switch(buff[0]) {
			case 'A':
				win = 2;
				draw = 1;
				loss = 3;
				break;
			case 'B':
				win = 3;
				draw = 2;
				loss = 1;
				break;
			case 'C':
				win = 1;
				draw = 3;
				loss = 2;
				break;
		}

                switch(buff[2]) {
                        case 'X':
				s += loss;
                                break;
                        case 'Y':
                                s += draw + 3;
                                break;
                        case 'Z':
                                s += win + 6;
                                break;
                }
        }
        fclose(f);
        printf("%d\n", s);

        return 0;
}

