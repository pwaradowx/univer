#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define GRAMS_IN_QUART 950
#define GRAMS_IN_MOLECULE 3e-23

void main()
{
	float quarts;
	float grams = 0;
	double moleculs = 0;

	printf("Enter amount of water in quarts: ");
	scanf("%f", &quarts);

	grams = quarts * GRAMS_IN_QUART;
	moleculs = grams / GRAMS_IN_MOLECULE;
	
	printf("%.3f quarts is equal to %lg moleculs.", quarts, moleculs);
}
