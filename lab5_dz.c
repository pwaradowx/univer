#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

void main()
{
	float x;
	float y;
	double z;
	float t;

	float res1;
	float res2;

	printf("x = ");
	scanf("%f", &x);
	printf("y = ");
	scanf("%f", &y);
	printf("z = ");
	scanf("%lg", &z);

	res1 = (2 * cos(x - M_PI / 6)) / (0.5 + pow(sin(y), 2));
	res2 = 1 + (pow(z, 2) / (3 - (pow(z, 2) / 5)));
	t = res1 * res2;

	printf("t is equal to: %f", t);
}
