#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>

double f1(double x)
{
	if (x <= 3)
	{
		return x * x - 3 * x + 9;
	}
	else
	{
		return 1 / (pow(x, 3) + 3);
	}
}

double f2(double x)
{
	return x * exp(sin(x * x));
}

void task1()
{
	int x;

	printf("Введите значение х: ");
	scanf("%d", &x);

	printf("fa(x)=%lf , fb(x)=%lf\n", f1(x), f2(x));

	printf("Произведение: %lf\n", f1(x)*f2(x));
	printf("Разность квадратов: %lf\n", f1(x)*f1(x) - f2(x)*f2(x));
	printf("Удвоенная сумма: %lf\n", (f1(x) + f2(x)) * 2);
}

void main()
{
	setlocale(LC_ALL, "Russian");

	task1();
}
