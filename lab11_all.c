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
    float B[21];
    float plussum = 0;
    int pluscount = 0;
    float minsum = 0;
    int mincount = 0;

    float x = 2;

    for (int i = 0; i < 21; i++)
    {
        B[i] = fabs(log(x)) - pow(x-2, 2);
        x += 0.1;
    }

    int j = 0;

    for (int i = 0; i < 100; i++)
    {
        if (j == 21) j = 0;
        A[i] = B[j];

        if (A[i] > 0)
        {
            plussum += A[i];
            pluscount++;
        }
        else
        {
            minsum += A[i];
            mincount++;
        }
        j++;
    }

    printf("Имя массива - А; Сумма положительных - %lf; Сумма отрицательных - %lf; Число положительных - %d; Число отрицательных - %d; Среднее значние - %lf",
        plussum, minsum, pluscount, mincount, (plussum + minsum) / 100);
}

void task3()
{
    int n;
    int A[100];

    float srednee = 0;

    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int temp = 0;

        printf("A[%d] = ", i);
        scanf("%d", &temp);

        A[i] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        srednee += A[i];
    }

    srednee /= n;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] < srednee)
        {
            count++;
        }
    }

    printf("Количество элементов, которые меньше среднего арифм. - %d", count);
}

void main()
{
    setlocale(LC_ALL, "Russian");

    task3();
}
