// test2.c
# include <stdio.h>
int main() {
	int a = 1, b = 1, c, d;
	c = a || --b;
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	d = a-- && --b;
	printf("a = %d, b = %d, d = %d\n", a, b, d);
	return 0;
}

