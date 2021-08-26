#include <stdio.h>
#include <limits.h>

int main()
{
	int a;
	float b;
	double c;

	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;
	printf("For int: ");
	printf("%d", a);
	printf(" ");
	printf("%lu\n", sizeof(a));

	printf("For float: ");
	printf("%f", b);
	printf(" ");
	printf("%lu\n", sizeof(b));

	printf("For double: ");
	printf("%f", c);
	printf(" ");
	printf("%lu\n", sizeof(c));


	return 0;
}