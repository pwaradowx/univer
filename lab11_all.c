#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 10

void task1()
{
	float A[10];
    float B[10];

    for (int i = 0; i < N; i++)
    {
        float temp;

        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);

        A[i] = temp;
        B[i] = temp;
    }

    for (int i = 0; i < N; i++)
    {
        if (A[i] == 0)
        {
            A[i] = i + 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%f\n", A[i]);
    }

    for (int i = 0; i < N; i++)
    {
        printf("| %2d | %3.1f | %3.1f |\n", i + 1, B[i], A[i]);
    }

    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
    }
    printf("Среднее арифметическое: %f", sum / N);
}

task2()
{
    float A[100];
    float x = 1;
    float y;

    for (int i = 0; i < 100; i++)
    {
        A[i] = abs(log(x)) - pow(x - 2, 2);
        x += 1;
    }

    float plussum = 0;
    int pluscounter = 0;
    float minsum = 0;
    int mincounter = 0;

    for (int i = 0; i < 100; i++)
    {
        if (A[i] > 0)
        {
            plussum += A[i];
            pluscounter++;
        }
        else if (A[i] < 0)
        {
            minsum += A[i];
            mincounter++;
        }
    }

    float plussrednee = plussum / pluscounter;

    printf("A[]: %.3f  %.3f  %d  %d  %.3f", plussum, minsum, pluscounter, mincounter, plussrednee);
}

void main()
{
    setlocale(LC_ALL, "Russian");

    task2();
}
