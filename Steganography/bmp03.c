// bmp03.c - Determine Header Size: 54 bytes + 4 * NumColors ..... 
// Skip Header bytes
// Make LSB of each pixel of the image = 0
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
	char *file1, *file2;
	int c, i, nch, bitPixel, placeValu, headerSize, numColors;
// Open Input file
	file1 = "lena.bmp";
	if ((ifp = fopen(file1, "r")) == NULL) {
		printf("Can't open %s\n", file1);
		return 1;
	} 
// Open Output file
	file2 = "lena3.bmp";
	if ((ofp = fopen(file2, "w")) == NULL) {
		printf("Can't open %s\n", file2);
		return 1;
	} 
// Skip (and copy) 28 bytes and find Bits_Per_Pixels in Bytes: 29-30 
	bitPixel = 0;
	placeValu = 1;
	for (nch = 0; nch < 28; nch++) {
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
	numColors = numColors1(bitPixel);
	headerSize = 54 + 4 * numColors;
	printf("\nbitPixel = %d, numColors = %d, Header Size = %d\n", bitPixel, numColors, headerSize);
// Skip (and copy) balance bytes of the header  
	for (nch = 30; nch < headerSize - 30; nch++) {
		c = getc(ifp);
		putc(c, ofp);
	}
// Take a byte of each pixel and make its LSB = 0, then copy such transformed bytes to output file
	for (i = 0; i < 10; i++) {		// 1111 1000      0111 1100   7c
		c = getc(ifp);
		printf("Original c = %x, ", c);
		c = c >> 1;
		printf("c after Right-shift = %x, ", c);
		c = c << 1;
		printf("c after Left-shift = %x, it has resulted in LSB = 0  ---\t", c);
		putc(c, ofp);
	}
//
	while ((c = getc(ifp)) != EOF) {
		c = c >> 1;
		c = c << 1;
		putc(c, ofp);
	}
// Close output file
	fclose(ofp);
	printf("\n");
	return 0;
}

