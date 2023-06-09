// rand01.c - to generate 4000 Random Numbers between 0 and 32,767
//
# include <stdio.h>
# include <stdlib.h>
//
void main() {
	int i, n, seed1, rand1, rand01[4000], randSorted[4000];
	seed1 = 100;
	n = 10;
	srand(100);
//
	printf("%d Random Numbers between 0 and 3999 are: ", n);
	for (i = 0; i < n; i++) {
		rand1 = rand() % 4000;
		printf("%d, ", rand1);
		rand01[i] = rand1;
	}
//
	printf("\n");
	srand(100);
//
	printf("2nd Set of %d Random Numbers between 0 and 4000 are: ", n);
	for (i = 0; i < n; i++) {
		rand1 = rand() % 4000;
		printf("%d, ", rand1);
		rand01[i] = rand1;
	}
//
	printf("\n");
}

