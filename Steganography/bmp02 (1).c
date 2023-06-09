// bmp02.c - Determine NumColors value, so that the Header Size can be obtained.
// Header Size: 54 bytes + 4 * NumColors ..... 
// Bytes 29-30 contain BitsPerPixel. NumColors = 2**BitsPerPixel
// Header_Size = 54 + 4 * NumColors 
# include <stdio.h>
// 
int numColors1(int bitsPerPixel) {
	int numColors, i;
	numColors = 1 << bitsPerPixel;
	return numColors;
}
//
int main() {
	FILE *ifp, *ofp;
	char *file1, *file2;
	int c, skip, nch, bitPixel, placeValu, headerSize, numColors;
// Open Input file
	file1 = "lena.bmp";
	if ((ifp = fopen(file1, "r")) == NULL) {
		printf("Can't open %s\n", file1);
		return 1;
	} 
// Open Output file
	file2 = "lena1.bmp";
	if ((ofp = fopen(file2, "w")) == NULL) {
		printf("Can't open %s\n", file2);
		return 1;
	} 
// Skip 28 bytes and find Bits_Per_Pixels in Bytes: 29-30 
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
	printf("\nbitPixel = %d, numColors = %d, Header Size = %d", bitPixel, numColors, headerSize);
// Copy balance bytes of input file to output file
	while ((c = getc(ifp)) != EOF) {
		putc(c, ofp);
	}
// Close output file
	fclose(ofp);
	printf("\n");
	return 0;
}

