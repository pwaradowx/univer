#include <stdio.h>
#include <locale.h>
#pragma warning(disable : 4996)

void main()
{
	int a;
	int b;

	setlocale(LC_ALL, "Russian");

	printf("Введите число А: ");
	scanf("%d", &a);
	printf("Введите число B: ");
	scanf("%d", &b);

	printf("-------------------\n");
	printf("| a*b | a+b | a-b |\n");
	printf("-------------------\n");
	printf("| %d*%d | %d+%d | %d-%d |\n", a, b, a, b, a, b);
	printf("-------------------\n");
	printf("| %3d | %3d | %3d |\n", a * b, a + b, a - b);
}
