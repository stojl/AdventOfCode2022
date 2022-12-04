#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define G 3

int main() {
	FILE *f;
	f = fopen("input.txt", "r");
	size_t len[G];
	memset(len, 0, sizeof(len));
	ssize_t read[G];
	char *buff[G];
	
	

	printf("Hello %zu\n", read[0]);

	return 0;
}
