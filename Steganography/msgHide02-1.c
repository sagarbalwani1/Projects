// msgHide02.c - Hide the given message followed by >
// Assumption: Message size <= 200 letters (including spaces). 
// Thus, a maximum of 200 * 4 = 800 + 1 ('>') = 801 bytes will be used to hide the message
# include <stdio.h>
# include <stdlib.h>
# define N 200
# define seed 1079
//
FILE *ifp, *ofp;
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
int numColors1(int bitsPerPixel) {
	int numColors;
	numColors = 1 << bitsPerPixel;
	return numColors;
}
//
int skipHeader1() {
	int c, nch, bitPixel, placeValu, headerSize, numColors, fileSize;
// Skip 2 bytes and read next 4 bytes to get the File Size
	for (nch = 0; nch < 2; nch++) {
		c = getc(ifp);
		putc(c, ofp);
	}
	fileSize = 0;
	placeValu = 1;
	while (nch < 6) {		// xxxx xxxx    xxxx xxxx  
		c = getc(ifp);
		putc(c, ofp);
		fileSize = fileSize + placeValu * c;
		printf("c=%x-, placeValu=%d-, fileSize=%d--- ", c, placeValu, fileSize);
		placeValu = placeValu * 256;
		nch += 1;
	}
//
// Skip (and copy) 28 bytes and find Bits_Per_Pixels in Bytes: 29-30 
	bitPixel = 0;
	placeValu = 1;
	while (nch < 28) {
		c = getc(ifp);
		putc(c, ofp);
		nch += 1;
	}
	while (nch < 30) {		
		c = getc(ifp);
		putc(c, ofp);
		printf("%x-", c);
		bitPixel = bitPixel + placeValu * c;
		placeValu = 256;
		nch += 1;
	}
	if (bitPixel <= 8) {
		numColors = numColors1(bitPixel);
		headerSize = 54 + 4 * numColors;
	}
	else {
		headerSize = 54 + 4;
	}
	printf("\nbitPixel = %d, numColors = %d, Header Size = %d", bitPixel, numColors, headerSize);
// Skip (and copy) balance bytes of the header  
	while (nch < headerSize) {
		c = getc(ifp);
		putc(c, ofp);
		nch += 1;
	}	
	printf("\n skipHeader: nch = %d, headerSize = %d\n", nch, headerSize);
	return headerSize;
}
//
int main() {
//	FILE *ifp, *ofp;
	char file1[16], file2[16];
	int c, i, j, m, n, headerSize, nch, msg, msgR1, c1, c2, seed1, rand1, rand01[N];
	n = N;
	seed1 = seed;
	printf("Enter the input file name: ");
	scanf("%s", file1);
//	file1 = "lena.bmp";
// Open inut file
	if ((ifp = fopen(file1, "r")) == NULL) {
		printf("Can't open %s\n", file1);
		return 1;
	} 
	printf("Enter the Output file name: ");
	scanf("%s", file2);
// Open Output file
//	file2 = "lena5.bmp";
	if ((ofp = fopen(file2, "w")) == NULL) {
		printf("Can't open %s\n", file2);
		return 1;
	} 
	headerSize = skipHeader1();
	printf("\n Header Size = %d\n", headerSize);
// Header has been skipped. 
//
	randNo1(seed1, rand01);
	printf("\n Random Numbers: ");
	for (i = 0; i < N; i++) {
		printf("%d, ", rand01[i]);
	}
	printf("\n");
	printf("\n Sorted Random Numbers: ");
	selectSort1(n, rand01);
	msg = getchar();
	printf("\n Enter the message to be hidden: ");
//
// Accept the message to be hidden from the user byte-by-byte and hide it
	nch = 0;
	j = 0;
	while ((msg = getchar()) != '\n') {
		for (i = 0; i < 4; i++) {
			rand1 = rand01[j++];
			while (rand1 <= nch) {
				rand1 = rand01[j++];
			} 
//			printf("\n<rand1=%d> ", rand1); 
			while (nch < rand1 && (c = getc(ifp)) != EOF) {
				putc(c, ofp);
				nch += 1;
//				printf("%x--", c);
			} 
/*
			printf("\nNext 9 bytes: ");
			for (m = 0; m < 9; m++) {
				c = getc(ifp);
				putc(c, ofp);
				nch += 1;
				printf("<nch=%d, c=%x> ", nch, c);
			}
			printf("\n");
*/
//
// Take the right-most 2-bits (2 LSBs)
			msgR1 = msg & 3;	
//	Read	 a byte from image file
			c = getc(ifp);
			nch += 1;	
// First write 00 in 2 LSBs of c and thereafter write (|) msgR1 in 2LSBs of c
			c1 = (c >> 2) << 2; 	
			c2 = c1 | msgR1;		
			printf("\n<nch=%d, msg=%x, msgR1=%x, c=%x, c1=%x, c2=%x> " , nch, msg, msgR1, c, c1, c2);
			putc(c2, ofp);  	
			msg = msg >> 2;	
//
		}
	}
//
// Write additional character ('>') in the output file to indicate End-of-Message
	rand1 = rand01[j++];
	while (nch < rand1 && (c = getc(ifp)) != EOF) {
		putc(c, ofp);
		nch += 1;
	} 
	c = '>';
	printf("\n Message Terminal Character (at nch = %d) = %c (%x)", nch, c, c);
	putc(c, ofp);
	nch += 1;
//
	while ((c = getc(ifp)) != EOF) {
		putc(c, ofp);
	}
//
// Close output file
	fclose(ofp);
	printf("\n");
	return 0;
}

