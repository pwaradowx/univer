#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void get_rashod_and_thick(float* rash, float* thick)
{
	printf("Введите расход шпаклевки на 1 м2, указанный на упаковке: ");
	scanf("%f", &*rash);

	printf("Введите желаемую толщину слоя: ");
	scanf("%f", &*thick);
}

float get_room_square()
{
	float room_square;

	printf("Введите суммарную площадь стен, потолка и пола: ");
	scanf("%f", &room_square);

	return room_square;
}

float get_holes_square()
{
	float holes_square;

	printf("Введите суммарную площадь окон и дверей в комнате: ");
	scanf("%f", &holes_square);

	return holes_square;
}

void calculate_shtukaturka(float holes_sq, float room_sq, float thickness, float rashod)
{
	float result;

	float square_to_work = room_sq - holes_sq;

	printf("Площадь для покрытия штукатуркой равна %.3f\n", square_to_work);

	printf("Считаем нужное количество штукатурки...\n");

	result = square_to_work * rashod * thickness + 1;

	printf("Количество штукатурки, нужное для покрытия вашей комнаты составляет %d кг\n", (int)result);
}

// Функция интерфейса меню.
void menu()
{
	printf("\nМеню: \n");
	printf("1) Ввести общую площадь комнаты\n");
	printf("2) Ввести площадь окон и дверей\n");
	printf("3) Ввести желаемую толщину слоя покрытия\n   И расход штукатурки на 1кв. метр\n");
	printf("4) Посчитать нужное количество штукатурки\n");
	printf("5) Выход\n");
}

void manual_input()
{
	float room_square = 0;
	float holes_square = 0;
	float thickness = 0;
	float rashod = 0;

	int ans = 0;

	printf("Добро пожаловать!\n");
	printf("Эта программа предназначена для расчета количества штукатурки для комнаты.\n");

	do
	{
		menu();

		printf("Введите номер команды: ");
		scanf("%d", &ans);

		switch (ans)
		{
		case 1:
			room_square = get_room_square();
			break;
		case 2:
			holes_square = get_holes_square();
			break;
		case 3:
			get_rashod_and_thick(&rashod, &thickness);
			break;
		case 4:
			if (room_square != 0 && holes_square != 0 && thickness != 0 && rashod != 0)
			{
				calculate_shtukaturka(holes_square, room_square, thickness, rashod);
				break;
			}
			else
			{
				printf("Введены не все необходимые значения!\n");
				continue;
			}
		case 5:
			exit(EXIT_SUCCESS);
		default:

			exit(EXIT_SUCCESS);
		}
	} while (ans <= 5);
}

void main()
{
	setlocale(LC_ALL, "Russian");

	manual_input();
}
