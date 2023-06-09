// msgHide01.c - Determine Header Size: 54 bytes + 4 * NumColors ..... 
// Skip Header bytes
// Complement 2 LSBs of each pixel of the image using exclusive-OR (^)
# include <stdio.h>
// 
int numColors1(int bitsPerPixel) {
	int numColors;
	numColors = 1 << bitsPerPixel;
	return numColors;
}
//
int main() {
	FILE *ifp, *ofp;
	char file1[16], file2[16];
	int c, i, nch, bitPixel, placeValu, headerSize, numColors, lsb2, lsb2c, fileSize, msg, msgR1, c1, c2;
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
// Skip 2 bytes and read next 4 bytes to get the File Size
	for (nch = 0; nch < 2; nch++) {
		c = getc(ifp);
		putc(c, ofp);
	}
	fileSize = 0;
	placeValu = 1;
	for (nch = 2; nch < 6; nch++) {		// xxxx xxxx    xxxx xxxx  
		c = getc(ifp);
		putc(c, ofp);
		fileSize = fileSize + placeValu * c;
		printf("c=%x-, placeValu=%d-, fileSize=%d--- ", c, placeValu, fileSize);
		placeValu = placeValu * 256;
	}
//
// Skip (and copy) 28 bytes and find Bits_Per_Pixels in Bytes: 29-30 
	bitPixel = 0;
	placeValu = 1;
	for (nch = 6; nch < 28; nch++) {
		c = getc(ifp);
		putc(c, ofp);
	}
	for (nch = 28; nch < 30; nch++) {		
		c = getc(ifp);
		putc(c, ofp);
		printf("%x-", c);
		bitPixel = bitPixel + placeValu * c;
		placeValu = 256;
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
	for (nch = 30; nch < headerSize; nch++) {
		c = getc(ifp);
		putc(c, ofp);
	}
// Header has been skipped. 
	msg = getchar();
	printf("\n Enter the message to be hidden: ");
// Accept the message to be hidden from the user byte-by-byte and hide it
	while ((msg = getchar()) != '\n') {
		for (i = 0; i < 4; i++) {
// Take the right-most 2-bits (2 LSBs)
// 			msg = 0100 1101
			msgR1 = msg & 3;		// 01-- 11
//	Read	 a byte from image file
			c = getc(ifp);			// 0010 1100 -- 0011 0111 -- 0100 0010
// First write 00 in 2 LSBs of c and thereafter write (|) msgR1 in 2LSBs of c
			c1 = (c >> 2) << 2; 		//	0010 1100
			c2 = c1 | msgR1;			//  0010 1100 | 0000 0001	= 0010 1101 = 2d
			printf("\n --- msg = %x--, msgR1 = %x--, c = %x--, c1 = %x--, c2 = %x---" , msg, msgR1, c, c1, c2);
			putc(c2, ofp);  	
			msg = msg >> 2;	// 0001 0011 -- 0000 0100	-- 0000 0001
		}
	}
//
	while ((c = getc(ifp)) != EOF) {
		putc(c, ofp);
	}
// Close output file
	fclose(ofp);
	printf("\n");
	return 0;
}

