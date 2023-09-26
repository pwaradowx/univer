#include <stdio.h>
#include <locale.h>

void main()
{
	int l = 333;
	int n = 2;
	int k = 3;
	int m = 1;

	setlocale(LC_ALL, "Russian");

	printf("Дано:\n%13d\n%13d\n        ________\nОтвет:\n%+10.2d%.3f", n, l, n / l, n * 1. / l);

	return 0;
}