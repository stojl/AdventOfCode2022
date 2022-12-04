#include <stdio.h>
#include <stdlib.h>

#define BUFF 100

int priority(char c) {
	if(c >= 97) {
		return c - 96;
	} else {
		return c - 38;
	}
}

int main() {
	FILE *f;
	f = fopen("input.txt", "r");
	char *buff = NULL;
	size_t len = 0;
	ssize_t read;
	int s = 0;
	while((read = getline(&buff, &len, f)) != -1) {
		for(int i = 0; i < (read - 1) / 2; ++i) {
			for(int j = (read - 1) / 2; j < read - 1; ++j) {
				if(buff[i] == buff[j]) {
					s += priority(buff[i]);
					i = read;
					break;
				}
			}
		}
	}

	printf("Sum is %d\n", s);
	fclose(f);
	return 0;
}
