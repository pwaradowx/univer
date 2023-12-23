#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct BuildingData
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
typedef struct BuildingData building_data;

void WelcomeMenu();
void ProgramMenu();
void ContinueRequest();
building_data SetupRoom();
building_data SetupMaterials();
void CalculateResult();
void ProgramExit();

void main()
{
	setlocale(LC_ALL, "Russian");

	WelcomeMenu();
	ProgramMenu();
}

// Фунция для вывода просто приветствия пользователя.
void WelcomeMenu()
{
	printf("Добро пожаловать!\n");
	printf("Эта программа поможет вам рассчитать количество штукатурки, необходимое для обделки комнаты.\n");
}

// Функция для вывода основного меню взаимодействия пользователя с программой.
void ProgramMenu()
{
	int command_id = 0;

	building_data data;
	building_data room_data;
	building_data material_data;
	double length;
	double width;
	double height;
	double layer_thickness;
	double consumption;

	printf("\n                          МЕНЮ                          \n");
	printf("----------------------------------------------------------\n");
	printf("| Ввести размеры комнаты и проемов             |    1    |\n");
	printf("----------------------------------------------------------\n");
	printf("| Ввести параметры материала                   |    2    |\n");
	printf("----------------------------------------------------------\n");
	printf("| Рассчитать количество необходимого материала |    3    |\n");
	printf("----------------------------------------------------------\n");
	printf("| Завершить работу                             |    4    |\n");
	printf("----------------------------------------------------------\n");

	while (command_id < 1 || command_id > 4)
	{
		printf("Введите номер команды: ");
		scanf("%d", &command_id);

		switch (command_id)
		{
		case 1:
			room_data = SetupRoom();
			data.room_length = room_data.room_length;
			data.room_width = room_data.room_width;
			data.room_height = room_data.room_height;
			break;
		case 2:
			material_data = SetupMaterials();
			data.layer_thickness = material_data.layer_thickness;
			data.consumption = material_data.consumption;
			break;
		case 3:
			CalculateResult(data);
			break;
		case 4:
			ProgramExit();
			break;
		default:
			printf("Введено некорректное значение!\nПопробуйте еще раз!\n \n");
			break;
		}
	}
}

// Функция для повторного использования программы без необходимости ее перезапуска.
void ContinueRequest()
{
	int answer;

	do
	{
		printf("Желаете продолжить?");
		printf("0 - нет. 1 - да.");
		printf("---> ");
		scanf("%d", &answer);
	} while (answer != 0 || answer != 1);

	if (answer == 0)
	{
		// Don't want to continue.
	}
	else
	{
		// Want to continue.
	}
}

// Функция для ввода данных о команате и проемах.
building_data SetupRoom()
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

	printf("Введите длину комнаты(см): ");
	scanf("%lf", &room_length);
	printf("Введите ширину комнаты(см): ");
	scanf("%lf", &room_width);
	printf("Введите высоту комнаты(см): ");
	scanf("%lf", &room_height);

	printf("Введите количество окон: ");
	scanf("%d", &window_count);
	printf("Введите высоту окна(см): ");
	scanf("%lf", &window_height);
	printf("Введите ширину окна(см): ");
	scanf("%lf", &window_width);

	printf("Введите количество дверей: ");
	scanf("%d", &door_count);
	printf("Введите высоту двери(см): ");
	scanf("%lf", &door_height);
	printf("Введите ширину двери(см): ");
	scanf("%lf", &door_width);

	building_data data;
	data.room_length = room_length;
	data.room_width = room_width;
	data.room_height = room_height;
	data.window_count = window_count;
	data.window_height = window_height;
	data.window_width = window_width;
	data.door_count = door_count;
	data.door_height = door_height;
	data.door_width = door_width;

	ContinueRequest();

	return data;

	ProgramMenu();
}

// Функция для ввода данных об используемом материале.
building_data SetupMaterials()
{
	double layer_thikness;
	double consumption;

	printf("Введите толщину слоя(мм): ");
	scanf("%lf", &layer_thikness);
	printf("Введите расход штукатурки(кг/м2): ");
	scanf("%lf", &consumption);

	ProgramMenu();
}

// Функция для расчета итогового результата и его вывода.
void CalculateResult(building_data data)
{
	double room_length = data.room_length;
	double room_width = data.room_width;
	double room_height = data.room_height;
	int window_count = data.window_count;
	double window_height = data.window_height;
	double window_width = data.window_width;
	int door_count = data.door_count;
	double door_height = data.door_height;
	double door_width = data.door_width;
	double layer_thickness = data.layer_thickness;
	double consumption = data.consumption;


	double room_square = room_length * room_height * 2 + room_width * room_height * 2 + room_length * room_width;
	double holes_square = window_count * window_height * window_width + door_count * door_height * door_width;
	double overall_square = room_square - holes_square;

	double result = overall_square * layer_thickness * consumption;

	printf("Считаем...\n");
	printf("Вам понадобится %lf кг штукатурки.");
}

// Фунция для завершения работы программы.
void ProgramExit()
{
	printf("Завершение работы...");
	exit(EXIT_SUCCESS);
}
