#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Функуция для запроса у пользователя на продолжение и проверки корректности принимаемого значения.
char continue_request()
{
	char ans = '0';
	bool correct_val = ans == 'y' || ans == 'n';

	while (!correct_val)
	{
		printf("Желаете продолжить? (y/n): ");

		scanf(" %c", &ans);

		correct_val = ans == 'y' || ans == 'n';

		if (!correct_val) 
		{ 
			printf("Введено некорректное значение!\n");
		}
		else if (ans == 'n')
		{
			printf("Закрываем программу...");
			exit(EXIT_SUCCESS);
		}
	}

	return ans;
}

// Функция интерфейса для ознакомления пользователя с функционалом программы.
void welcome_menu()
{
	printf("Добро пожаловать!\n");
	printf("Эта программа предназначена для расчета количества штукатурки для комнаты.\n");
	
	continue_request();
}

void setup_start_data(float *rash, float *thick)
{
	printf("Введите расход шпаклевки на 1 м2, указанный на упаковке: ");
	scanf("%f", &*rash);

	continue_request();

	printf("Введите желаемую толщину слоя: ");
	scanf("%f", &*thick);

	continue_request();
}

float get_room_square()
{
	float room_square;

	printf("Введите суммарную площадь стен, потолка и пола: ");
	scanf("%f", &room_square);

	continue_request();

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

	float rashod_sht;
	float layer_thickness;

	float square_to_work = room_sq - holes_sq;

	printf("Площадь для покрытия штукатуркой равна %.3f\n", square_to_work);

	setup_start_data(&rashod_sht, &layer_thickness);

	printf("Считаем нужное количество штукатурки...\n");

	if (thickness == 0)
	{
		result = square_to_work * rashod_sht * layer_thickness + 1;
	}
	else
	{
		result = square_to_work * rashod * thickness + 1;
	}

	printf("Количество штукатурки, нужное для покрытия вашей комнаты составляет %d кг", (int)result);
}

void manual_input()
{
	welcome_menu();
	calculate_shtukaturka(get_holes_square(), get_room_square(), 0, 0);
}

void file_io()
{
	FILE* file;

	file = fopen("inputdata.txt", "r");
	float data[4];
	int i = 0;

	while (fscanf(file, "%f", &data[i]) != EOF)
	{
		i++;
	}

	calculate_shtukaturka(data[1], data[0], data[3], data[2]);
}

void main()
{
	setlocale(LC_ALL, "Russian");

	manual_input();
}
