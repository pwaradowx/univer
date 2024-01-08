// бИСТ-235 Колимбет Семён

/*
* Этот файл представляет из себя программу 
* для расчета штукатурки на указанную площадь помещения.
* Он содержит:
*	struct buildingData - структура для хранения данных о
*		площади помещения и парамаетрах материала.
*	void main() - главня функция.
*	void programMenu() - функция, реализующая графическое
*		взаимодействия пользователя и программы через меню.
*	void setupRoom() - функция для ввода данных о 
		параметрах комнаты и проемах.
*	void setupMaterial() - функция для ввода данных о 
*		параметрах используемого материала.
*	void calculateResult() - функция для вывода
*		результатов вычислений в консоль.
*	void continueRequest() - функция для запроса у 
*		пользователя на продолжение работы программы
*		или ее завершение.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

struct buildingData
{
	double room_length;
	double room_width;
	double room_height;

	int window_count;
	double window_height;
	double window_width;

	int door_count;
	double door_height;
	double door_width;

	double layer_thickness;
	double consumption;
};
typedef struct buildingData building_data;

void programMenu(building_data*);
void setupRoom(building_data*);
void setupMaterial(building_data*);
void calculateResult(building_data*);
void continueRequest(building_data*);

void main()
{
	setlocale(LC_ALL, "Russian");

	building_data data = {0};

	programMenu(&data);
}

// Функция для вывода основного меню взаимодействия пользователя с программой.
void programMenu(building_data *pData)
{
	int command_id = 0;

	printf("\n                    |МЕНЮ|\n");
	printf("1 - Ввести размеры комнаты и проемов\n");
	printf("2 - Ввести параметры материала\n");
	printf("3 - Рассчитать количество необходимого материала\n");

	while (command_id < 1 || command_id > 3)
	{
		printf("Введите номер команды: ");
		scanf("%d", &command_id);
	}

	switch (command_id)
	{
	case 1:
		setupRoom(pData);
		break;
	case 2:
		setupMaterial(pData);
		break;
	case 3:
		calculateResult(pData);
		break;
	default:
		break;
	}
}

// Функция для ввода данных о команате и проемах.
void setupRoom(building_data *pData)
{
	double room_length, room_width, room_height;

	int window_count, door_count;
	double window_height, window_width, door_height, door_width;

#pragma region SetupRoom
	printf("Введите длину комнаты(см): ");
	scanf("%lf", &room_length);
	printf("Введите ширину комнаты(см): ");
	scanf("%lf", &room_width);
	printf("Введите высоту комнаты(см): ");
	scanf("%lf", &room_height);

	while (room_length == 0 || room_width == 0 || room_height == 0)
	{
		printf("Упс! Вы где-то ошиблись, попробуйте еще раз!\n");
		printf("Введите длину комнаты(см): ");
		scanf("%lf", &room_length);
		printf("Введите ширину комнаты(см): ");
		scanf("%lf", &room_width);
		printf("Введите высоту комнаты(см): ");
		scanf("%lf", &room_height);
	}
	pData->room_length = room_length / 100;
	pData->room_width = room_width / 100;
	pData->room_height = room_height / 100;
#pragma endregion

#pragma region SetupWindows
	printf("Введите количество окон: ");
	scanf("%d", &window_count);

	while (window_count < 0)
	{
		printf("Количество окон не может быть отрицательным! Попробуйте еще раз!\n");
		printf("Введите количество окон: ");
		scanf("%d", &window_count);
	}
	pData->window_count = window_count;

	if (window_count != 0)
	{
		printf("Введите высоту окна(см): ");
		scanf("%lf", &window_height);
		printf("Введите ширину окна(см): ");
		scanf("%lf", &window_width);

		while (window_height == 0 || window_width == 0)
		{
			printf("Упс! Вы где-то ошиблись, попробуйте еще раз!\n");
			printf("Введите высоту окна(см): ");
			scanf("%lf", &window_height);
			printf("Введите ширину окна(см): ");
			scanf("%lf", &window_width);
		}

		pData->window_height = window_height / 100;
		pData->window_width = window_width / 100;
	}
#pragma endregion

#pragma region SetupDoors
	printf("Введите количество дверей: ");
	scanf("%d", &door_count);

	while (door_count < 0)
	{
		printf("Количество дверей не может быть отрицательным! Попробуйте еще раз!\n");
		printf("Введите количество дверей: ");
		scanf("%d", &door_count);
	}
	pData->door_count = door_count;

	if (door_count != 0)
	{
		printf("Введите высоту дверей(см): ");
		scanf("%lf", &door_height);
		printf("Введите ширину дверей(см): ");
		scanf("%lf", &door_width);

		while (door_height == 0 || door_width == 0)
		{
			printf("Упс! Вы где-то ошиблись, попробуйте еще раз!\n");
			printf("Введите высоту дверей(см): ");
			scanf("%lf", &door_height);
			printf("Введите ширину дверей(см): ");
			scanf("%lf", &door_width);
		}

		pData->door_height = door_height / 100;
		pData->door_width = door_width / 100;
	}
#pragma endregion

	programMenu(pData);
}

// Функция для ввода данных об используемом материале.
void setupMaterial(building_data *pData)
{
	double layer_thikness, consumption;

	printf("Введите толщину слоя(мм): ");
	scanf("%lf", &layer_thikness);

	while (layer_thikness <= 0)
	{
		printf("Вы где-то ошиблись! Попробуйте еще раз!\n");
		printf("Введите толщину слоя(мм): ");
		scanf("%lf", &layer_thikness);
	}

	printf("Введите расход штукатурки(кг/м2): ");
	scanf("%lf", &consumption);

	while (consumption <= 0)
	{
		printf("Вы где-то ошиблись! Попробуйте еще раз!\n");
		printf("Введите расход штукатурки(кг/м2): ");
		scanf("%lf", &consumption);
	}

	pData->layer_thickness = layer_thikness;
	pData->consumption = consumption;

	programMenu(pData);
}

// Функция для расчета итогового результата и его вывода.
void calculateResult(building_data *pData)
{
	double room_length = pData->room_length;
	double room_width = pData->room_width;
	double room_height = pData->room_height;
	int window_count = pData->window_count;
	double window_height = pData->window_height;
	double window_width = pData->window_width;
	int door_count = pData->door_count;
	double door_height = pData->door_height;
	double door_width = pData->door_width;
	double layer_thickness = pData->layer_thickness;
	double consumption = pData->consumption;


	double room_square = room_length * room_height * 2 + room_width * room_height * 2 + room_length * room_width;
	double holes_square = window_count * window_height * window_width + door_count * door_height * door_width;
	double overall_square = room_square - holes_square;

	double result = ceil(overall_square * layer_thickness * consumption);

	printf("Считаем...\n");
	printf("Вам понадобится %.2lf кг штукатурки.\n", result);

	continueRequest(pData);
}

// Функция для повторного использования программы без необходимости ее перезапуска.
void continueRequest(building_data *pData)
{
	int answer;

	do
	{
		printf("Желаете продолжить?\n");
		printf("1-да. 0-нет.\n");
		printf("---> ");
		scanf("%d", &answer);
	} while (answer != 0 && answer != 1);

	if (answer == 0)
	{
		printf("Завершение работы...");
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("Введенные ранее значения сохранены!\nИх можно изменить используя меню!\n");
		programMenu(pData);
	}
}
