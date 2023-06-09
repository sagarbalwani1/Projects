// bmp01.c - copy .bmp file
// Header Size: 54 bytes + 4 * NumColor ..... 
//
# include <stdio.h>
// 
int main() {
	FILE *ifp, *ofp;
	char *file1, *file2;
	file1 = "lena.bmp";
	file2 = "lena1.bmp";
	int c, nch;
// Open inut file
	if ((ifp = fopen(file1, "r")) == NULL) {
		printf("Can't open %s\n", file1);
		return 1;
	} 
// Open output file
	if ((ofp = fopen(file2, "w")) == NULL) {
		printf("Can't open %s\n", file2);
		return 1;
	} 
	nch = 0;
	while ((c = getc(ifp)) != EOF) {		
		putc(c, ofp);
	}
	fclose(ofp);
	printf("\n");
	return 0;
}

