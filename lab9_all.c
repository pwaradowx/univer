#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define ROW 9
#define COL 9

void basic_pifagor()
{
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			printf("%2d ", i * j);
		}

		printf("\n");
	}
}

void left_low_pifagor()
{
	int row = 9;
	int col = 0;

	for (int i = 2; i <= row; i++)
	{
		col++;

		for (int j = 1; j <= col; j++)
		{
			printf("%2d ", i * j);
		}

		printf("\n");
	}
}

void task1()
{
	int row = 9;
	int col = 0;

	int start = 31;
	int a = 31;

	for (int i = 2; i <= row; i++)
	{
		a = start - i + 1;
		col++;

		for (int j = 1; j <= col; j++)
		{
			printf("%2d ", a);
			a++;
		}

		printf("\n");
	}
}

void task2()
{
	int input;

	printf("Введите число: ");
	scanf("%d", &input);

	int a = 0;
	int b = 0;
	int counter = 1;

	while (input != 0)
	{
		if (counter % 2 != 0)
		{
			a += input % 10;
		}
		else
		{
			b += input % 10;
		}

		input /= 10;
		counter++;
	}

	printf("Результат равен: %d", a * b);
}

void task3()
{
	char symb;
	int high;
	int length;

	printf("Введите символ из которого будет строиться фигура: ");
	scanf("%c", &symb);
	printf("\nВведите высоту: ");
	scanf("%d", &high);
	printf("\nВведит длину верхней грани: ");
	scanf("%d", &length);

	int i, j, k;

	for (i = 1; i <= high; i++) {
		for (j = high - i; j > 0; j--) {
			printf(" ");
		}

		for (k = 1; k <= length; k++) {
			printf("%c", symb);
		}

		length += 2;
		printf("\n");
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");

	task3();
}
