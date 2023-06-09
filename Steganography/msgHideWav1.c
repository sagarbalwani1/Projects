// msgHideWav1.c - Hide the message in a wav file terminated by >.
// Skip Header bytes (2000 bytes)
//
# include <stdio.h>
int main() {
	FILE *ifp, *ofp;
	char file1[16], file2[16];
	int c, i, j, nch, bitPixel, placeValu, headerSize, numColors, lsb2, lsb2c, fileSize, msg, msgR1, c1, c2;
	printf("Enter the input file name: ");
	scanf("%s", file1);
// Open inut file
	if ((ifp = fopen(file1, "r")) == NULL) {
		printf("Can't open %s\n", file1);
		return 1;
	} 
	printf("Enter the Output file name: ");
	scanf("%s", file2);
// Open Output file
	if ((ofp = fopen(file2, "w")) == NULL) {
		printf("Can't open %s\n", file2);
		return 1;
	} 
// Skip 2000 bytes for Header of wav file 
	nch = 0;
	while (nch < 2000) {
		c = getc(ifp);
		putc(c, ofp);
		nch += 1;
	}
// Header has been skipped. 
//
	msg = getchar();
	printf("\n Enter the message to be hidden: ");
// Accept the message to be hidden from the user byte-by-byte and hide it
	while ((msg = getchar()) != '\n') {
		for (i = 0; i < 4; i++) {
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
		}
	}
//
// Write additional character ('>') in the output file to indicate End-of-Message
	c = '>';
	printf("\n Message Terminal Character = %c (%x)", c, c);
	putc(c, ofp);
//
	while ((c = getc(ifp)) != EOF) {
		putc(c, ofp);
	}
// Close output file
	fclose(ofp);
	printf("\n");
	return 0;
}

