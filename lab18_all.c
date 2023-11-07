#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

struct point {
    float x;
    float y;
    char name;
};

typedef struct point Point;

void put_point(Point z)
{
    printf("point %c (%.1f, %.1f)", z.name, z.x, z.y);
}

void dist(Point a, Point b)
{
    float result = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    printf("Декартово расстояние равно - %lf", result);
}

Point seredina(Point a, Point b)
{
    Point s;
    s.name = "S"; s.x = (a.x + b.x) / 2; s.y = (a.y + b.y) / 2;
    return s;
}

void chetvert(Point a)
{
    if (a.x > 0)
    {
        if (a.y > 0)
        {
            printf("1 четверть");
        }
        else
        {
            printf("4 четверть");
        }
    }
    else
    {
        if (a.y > 0)
        {
            printf("2 четверть");
        }
        else
        {
            printf("3 четверть");
        }
    }
}

void task1()
{
    Point b, a;

    a = (Point){ 1.f, 2.f, 'A' };
    b.name = 'B'; b.x = 5; b.y = -3;

    put_point(a);
    dist(a, b);
    seredina(a, b);
    chetvert(seredina(a, b));
}

void main()
{
    setlocale(LC_ALL, "Russian");

    task1();
}
