// msgRecover01a.c - Determine Header Size: 54 bytes + 4 * NumColors ..... 
// Skip Header bytes
// Recover the message which ends with >>>.
# include <stdio.h>
// 
int numColors1(int bitsPerPixel) {
	int numColors;
	numColors = 1 << bitsPerPixel;
	return numColors;
}
//
int main() {
	FILE *ifp;
	char file1[16], file2[16];
	int c, i, j, nch, bitPixel, placeValu, headerSize, numColors, lsb2, lsb2c, fileSize, msg, msgR1, c1, c2;
	printf("Enter the input file name, which contains hidden message: ");
	scanf("%s", file1);
//	file1 = "lena1.bmp";
// Open inut file
	if ((ifp = fopen(file1, "r")) == NULL) {
		printf("Can't open %s\n", file1);
		return 1;
	} 
// Skip 2 bytes and read next 4 bytes to get the File Size
	for (nch = 0; nch < 2; nch++) {
		c = getc(ifp);
	}
	fileSize = 0;
	placeValu = 1;
	for (nch = 2; nch < 6; nch++) {		// xxxx xxxx    xxxx xxxx  
		c = getc(ifp);
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
	}
	for (nch = 28; nch < 30; nch++) {		
		c = getc(ifp);
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
	}
// Header has been skipped. ... Message recovery will start byte-by-byte.
	i = 0;
	msg = 0;
	printf("\n Hidden message is: \n");	
	while ((c = getc(ifp)) != '>' && c != EOF) {
// Take the right-most 2-bits (2 LSBs) of c and put them in appropriate position in msg
		j = 2 * i;
		c1 = (c & 3);
		c2 = c1 << j;
		msg = msg | c2;	
// 	
		printf("<c=%x, c1=%x, c2=%x, msg=%x" , c, c1, c2, msg);
		i += 1;
		if (i >= 4) {
			printf("(%c)>\n", msg);
			printf("\n");
			i = 0;
			msg = 0;
		}
	}
//
	printf("\n");
	return 0;
}

