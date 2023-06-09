// msgRecoverWav1.c - Recover the message which ends with >
// Skip Header bytes (2000 bytes)
// 
# include <stdio.h>
//
int main() {
	FILE *ifp;
	char file1[16], file2[16];
	int c, i, j, nch, bitPixel, placeValu, headerSize, numColors, lsb2, lsb2c, fileSize, msg, msgR1, c1, c2;
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
	i = 0;
	msg = 0;
	printf("\n Hidden message is: \n");	
	while ((c = getc(ifp)) != '>' && c != EOF) {
// Take the right-most 2-bits (2 LSBs) of c and put them in appropriate position in msg
		nch += 1;
		j = 2 * i;
		c1 = (c & 3);
		c2 = c1 << j;
		msg = msg | c2;	
// 	
		printf("<nch=%d, c=%x, c1=%x, c2=%x, msg=%x" , nch, c, c1, c2, msg);
		i += 1;
		if (i >= 4) {
			printf("(%c)>\n", msg);
			printf("\n");
			i = 0;
			msg = 0;
		}
	}
	printf("\nMessage terminal character (>) is found ... Complete message is recovered ...");
//
	printf("\n");
	return 0;
}

