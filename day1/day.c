#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFSIZE 50

void insert_order(int *a, int n, int x) {
	int m = n;
	if(x > a[0]) {
		m = 0;
	} else {
		for(int i = 0; i < n - 1; ++i)
			if(a[i] >= x && x >= a[i + 1]) {
				m = i + 1;
				break;
			}
	}
	for(int i = n - 1; m < i; --i)
		a[i] = a[i - 1];
	if(m < n) a[m] = x; 
}

int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("Argument needed\n");
		return 1;
	}

	int M = atoi(argv[1]);

	FILE *f;

	f = fopen("input.txt", "r");
	int s = 0;
	int *S = (int*)malloc(sizeof(int) * M);
	memset(S, 0, sizeof(int) * M);
	char *buff = (char*)malloc(sizeof(char) * BUFFSIZE);
	
	while(fgets(buff, BUFFSIZE, f) != NULL) {
		if(buff[0] == '\n') {
			insert_order(S, M, s);
			s = 0;
			continue;
		}
		s += atoi(buff);
	}
	s = 0;
	for(int i = 0; i < M; ++i)
		s += S[i];

	printf("Max of %d elves: %d\n", M, s);
	fclose(f);
	free(buff);
	free(S);
	return 0;
}
