// cpWav01.c - Copy wave file and print a few important header content ... 
//
# include <stdio.h>
//
FILE *ifp, *ofp;
int main() {
	int i, nch, c, fileType, fileSize1, nChannels, bitsPerSample, data, fileSize2, placeValu, lenFormat, formatType, sampleRate;
	char file1[16], file2[16];
	printf("Enter the input file name: ");
	scanf("%s", file1);
// Open inut file
	if ((ifp = fopen(file1, "r")) == NULL) {
		printf("Can't open %s\n", file1);
		return 1;
	} 
	printf("Enter the Output file name: ");
	scanf("%s", file2);
	if ((ofp = fopen(file2, "w")) == NULL) {
		printf("Can't open %s\n", file2);
		return 1;
	} 
//
// Print 1st four characters ... 
	printf("\nFile Type: ");
	for (nch = 0; nch < 4; nch++) {
		c = getc(ifp);
		printf("%c", c);
		putc(c, ofp);
	}
// Print File Size (5-8 bytes)
	fileSize1 = 0;
	placeValu = 1;
	while (nch < 8) {
		c = getc(ifp);
		nch += 1;
		putc(c, ofp);
		fileSize1 = fileSize1 + placeValu * c;
		placeValu = placeValu * 256;
	}
	printf("\n File Size-1 = %d", fileSize1);
// File type header "WAVE" (9-12 bytes)
	printf("\nFile Type Header: ");
	while (nch < 12) {
		c = getc(ifp);
		nch += 1;
		putc(c, ofp);
		printf("%c", c);
	}
// Format chunk marker "fmt " (13-16 bytes)
	printf("\nFormat chunk marker: ");
	while (nch < 16) {
		c = getc(ifp);
		nch += 1;
		putc(c, ofp);
		printf("%c", c);
	}
// Length of Format data (17-20 bytes)
	lenFormat = 0;
	placeValu = 1;
	while (nch < 20) {
		c = getc(ifp);
		nch += 1;
		putc(c, ofp);
		lenFormat = lenFormat + placeValu * c;
		placeValu = placeValu * 256;
	}
	printf("\nLength of format data = %d", lenFormat);
// Type of Format - 1 for PCM (21-22 bytes)
	formatType = 0;
	placeValu = 1;
	while (nch < 22) {
		c = getc(ifp);
		nch += 1;
		putc(c, ofp);
		formatType = formatType + placeValu * c;
		placeValu = placeValu * 256;
	}
	printf("\nType of Format = %d", formatType);
// Number of channels (23-24 bytes)
	nChannels = 0;
	placeValu = 1;
	while (nch < 24) {
		c = getc(ifp);
		nch += 1;
		putc(c, ofp);
		nChannels = nChannels + placeValu * c;
		placeValu = placeValu * 256;
	}
	printf("\nNumber of Channels = %d", nChannels);
// Sample Rate (25-28 bytes)
	sampleRate = 0;
	placeValu = 1;
	while (nch < 28) {
		c = getc(ifp);
		nch += 1;
		putc(c, ofp);
		sampleRate = sampleRate + placeValu * c;
		placeValu = placeValu * 256;
	}
	printf("\nSample Rate = %d", sampleRate);
// Skip up to byte = 34
	while (nch < 34) {
		c = getc(ifp);
		nch += 1;
		putc(c, ofp);
	}
// Bits per sample (35-36 bytes)
	bitsPerSample = 0;
	placeValu = 1;
	while (nch < 36) {
		c = getc(ifp);
		nch += 1;
		putc(c, ofp);
		bitsPerSample = bitsPerSample + placeValu * c;
		placeValu = placeValu * 256;
	}
	printf("\nBits per Sample = %d", bitsPerSample);
// Print DatChunk Header: "data" (37-40 bytes)
	printf("\nData Chunk Header: ");
	while (nch < 40) {
		c = getc(ifp);
		nch += 1;
		putc(c, ofp);
		printf("%c", c);
	}
// Size of Data Section (41-44 bytes)
	fileSize2 = 0;
	placeValu = 1;
	while (nch < 44) {
		c = getc(ifp);
		nch += 1;
		putc(c, ofp);
		fileSize2 = fileSize2 + placeValu * c;
		placeValu = placeValu * 256;
	}
	printf("\nSize of Data Section = %d", fileSize2);
//
	while ((c = getc(ifp)) != EOF) {
		nch += 1;
		putc(c, ofp);
	}
	printf("\n No. of bytes in File = %d", nch);
	printf("\n");
// Close output file
	fclose(ofp);
	return 0;
} 
