// msgRecoverWav2.c - Recover the message which ends with > and is stored in sorted randomly genertaed bytes
// Assumption: Message size <= 200 letters (including spaces). 
// Thus, a maximum of 200 * 4 = 800 + 1 ('>') = 801 bytes will be used to hide the message
//
# include <stdio.h>
# include <stdlib.h>
# define N 400
# define seed 1079
//
FILE *ifp;
// 
// Sorting of an array by finding minimum value repeatedly (Selection Sort) ... 
void selectSort1(int n, int a[]) {
	int min, i, j, k, jmin, temp;
	for (i = 0; i < n; i++) {
		jmin = i;
		for (j = i+1; j < n; j++) {
			if (a[j] < a[jmin]) {
				jmin = j;
			}
		}
		temp = a[i];
		a[i] = a[jmin];
		a[jmin] = temp;
	}
	for (k = 0; k < n; k++) {
		printf("%d, ", a[k]);
	}
	printf("\n");
}
//
void randNo1(int seed1, int rand01[]) {
	int i, rand1;
	srand(seed1);
//
	for (i = 0; i < N; i++) {
		rand1 = rand() % 4000;
//		printf("%d, ", rand1);
		rand01[i] = rand1;
	}
}
//
int main() {
	char file1[16], file2[16];
	int c, i, j, k, m, n, nch, headerSize, msg, c1, c2, seed1, rand1, rand01[1000];
	printf("Enter the input file name, which contains hidden message: ");
	scanf("%s", file1);
// Open inut file
	if ((ifp = fopen(file1, "r")) == NULL) {
		printf("Can't open %s\n", file1);
		return 1;
	} 
	nch = 0;
	while (nch < 2000) {
		c = getc(ifp);
		nch += 1;
	}
// Header has been skipped. ... Message recovery will start byte-by-byte.
//
	n = N;
	seed1 = seed;
	randNo1(seed1, rand01);
	printf("\n Random Numbers: ");
	for (i = 0; i < N; i++) {
		printf("%d, ", rand01[i]);
	}
	printf("\n");
	printf("\n Sorted Random Numbers: ");
	selectSort1(n, rand01);
//
	i = 0;
	msg = 0;
	printf("\n Hidden message is: \n");	
	nch = 0;
	k = 0;
	while (c != '>' && (c = getc(ifp)) != EOF) {
		nch += 1;
		rand1 = rand01[k++];
		while (rand1 < nch) {
			rand1 = rand01[k++];
		}
//		printf("\n<rand1=%d> %x--", rand1, c); 
		while (nch < rand1) {
			c = getc(ifp);
			nch += 1;
//			printf("%x--", c);
		}
//
// Take the right-most 2-bits (2 LSBs) of c and put them in appropriate position in msg
		c = getc(ifp);
		if (c == '>') {
			printf("\n Message termination character ('>') is found ... Message is fully recovered ... \n");
			break;
		}
		nch += 1;
		j = 2 * i;
		c1 = (c & 3);
		c2 = c1 << j;
		msg = msg | c2;	
// 	
		printf("<nch=%4d, c=%2x, c1=%x, c2=%2x, msg=%2x ---" , nch, c, c1, c2, msg);
		i += 1;
		if (i >= 4) {
			printf("(%c)>", msg);
			printf("\n");
			i = 0;
			msg = 0;
		}
//
	}
//
	printf("\n");
	return 0;
}

