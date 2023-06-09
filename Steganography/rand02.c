// rand02.c - to generate 4000 Random Numbers between 0 and 32,767
// Sort the random numbers and store their index in an array.
//
# include <stdio.h>
# include <stdlib.h>
# define N 4000
//
// Sorting of an array by finding minimum value repeatedly ... 
void sort01(int n, int a[], int aIndex[]) {
	int min, i, j, k, jmin, temp, b[N];
	for (i = 0; i < n; i++) {
		b[i] = a[i];
	}
	for (i = 0; i < n; i++) {
		jmin = 0;
		for (j = 1; j < n; j++) {
			if (b[j] < b[jmin]) {
				jmin = j;
			}
		}
		aIndex[i] = jmin;
		b[jmin] = 99999;
	}
	for (k = 0; k < n; k++) {
		printf("%d, ", aIndex[k]);
	}
	printf("\n");
}
//
// Sorting of an array using Insertion Sort
void insertSort1(int n, int a[]) {
	int i, j, k, temp;
	for (i = 1; i < n; i++) {
		j = i - 1;
		temp = a[i];
		while (a[i] < a[j]) {
			j = j - 1;
		}
		for (k = i; k >= j + 2; k--) {
			a[k] = a[k-1];
		}
		a[j+1] = temp;
//
		printf("i = %d>> ", i);
		for (k = 0; k <= i; k++) {
			printf("%d, ", a[k]);
		}
		printf("\n");
	}
}
//
void randNo1(int n, int seed1, int rand01[]) {
	int i, rand1;
	srand(seed1);
//
	for (i = 0; i < n; i++) {
		rand1 = rand() % 4000;
		printf("%d, ", rand1);
		rand01[i] = rand1;
	}
}
//
void main() {
	int i, n, seed1, rand1, rand01[N], randSortIndex[N];
	seed1 = 100;
	n = 10;
	printf("%d Random Numbers between 0 and 4000 are: ", n);
	randNo1(n, seed1, rand01);
	printf("\n");
//
//	insertSort1(n, rand01);
	sort01(n, rand01, randSortIndex);
//
//	printf("\n%d Random Numbers in sorted order are: ", n);
//	for (i = 0; i < n; i++) {
//		printf("%d, ", rand01[i]);
//	}
	printf("\nIndices of %d Random Numbers in sorted order are: ", n);
	for (i = 0; i < n; i++) {
		printf("%d, ", randSortIndex[i]);
	}
	printf("\n");
}

