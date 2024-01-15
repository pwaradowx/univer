// бИСТ-235 Колимбет Семён

/*
* Этот файл представляет из себя программу 
* для расчета штукатурки на указанную площадь помещения.
* Он содержит:
*	struct buildingData - структура для хранения данных о
*		площади помещения и парамаетрах материала.
*	int main() - главня функция.
*	building_data loadBuildingData() - функция, загружающая 
		ранее используемые данные из файла.
*	int programMenu() - функция, реализующая графическое
*		взаимодействия пользователя и программы через меню.
*	int setupRoom() - функция для ввода данных о 
		параметрах комнаты и проемах.
*	int setupMaterial() - функция для ввода данных о 
*		параметрах используемого материала.
*	int calculateResult() - функция для вывода
*		результатов вычислений в консоль.
*	int continueRequest() - функция для запроса у 
*		пользователя на продолжение работы программы
*		или ее завершение.
*	int saveBuildingData() - сохраняет введенные значения
*		в файл для повторного использования.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#define FILE_NAME "shtukaturka.txt";

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

building_data loadBuildingData();
int programMenu(building_data*);
int setupRoom(building_data*);
int setupMaterial(building_data*);
int calculateResult(building_data*);
int continueRequest(building_data*);
int saveBuildingData(building_data*);

int main()
{
	setlocale(LC_ALL, "Russian");

	building_data data = loadBuildingData();

	programMenu(&data);
}

// Функция для загрузки ранее используемых данных.
building_data loadBuildingData()
{
	const building_data empty_data = {0};
	building_data loaded_data = {0};

	FILE* file;
	const char* filename = FILE_NAME;
	char buffer[1024];

	file = fopen(filename, "r");
	if (file == NULL)
	{
		// Файл с данными не был найден, поэтому начинаем все с чистого листа.
		return empty_data;
	}

	int c = 0;
	while (fgets(buffer, sizeof(buffer), file) != NULL) {
		printf("%s", buffer);

		switch (c)
		{
			case 1:
				sscanf(buffer, "%lf", &loaded_data.room_length);
				break;
			case 3:
				sscanf(buffer, "%lf", &loaded_data.room_width);
				break;
			case 5:
				sscanf(buffer, "%lf", &loaded_data.room_height);
				break;
			case 7:
				sscanf(buffer, "%d", &loaded_data.window_count);
				break;
			case 9:
				sscanf(buffer, "%lf", &loaded_data.window_height);
				break;
			case 11:
				sscanf(buffer, "%lf", &loaded_data.window_width);
				break;
			case 13:
				sscanf(buffer, "%d", &loaded_data.door_count);
				break;
			case 15:
				sscanf(buffer, "%lf", &loaded_data.door_height);
				break;
			case 17:
				sscanf(buffer, "%lf", &loaded_data.door_width);
				break;
			case 19:
				sscanf(buffer, "%lf", &loaded_data.layer_thickness);
				break;
			case 21:
				sscanf(buffer, "%lf", &loaded_data.consumption);
				break;
			default:
				break;
		}
		c++;
	}

	fclose(file);

	return loaded_data;
}

// Функция для вывода основного меню взаимодействия пользователя с программой.
int programMenu(building_data *pData)
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

	return 0;
}

// Функция для ввода данных о команате и проемах.
int setupRoom(building_data *pData)
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
	pData->room_length = room_length;
	pData->room_width = room_width;
	pData->room_height = room_height;
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

		pData->window_height = window_height;
		pData->window_width = window_width;
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

		pData->door_height = door_height;
		pData->door_width = door_width;
	}
#pragma endregion

	programMenu(pData);

	return 0;
}

// Функция для ввода данных об используемом материале.
int setupMaterial(building_data *pData)
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

	return 0;
}

// Функция для расчета итогового результата и его вывода.
int calculateResult(building_data *pData)
{
	double room_length = pData->room_length / 100;
	double room_width = pData->room_width / 100;
	double room_height = pData->room_height / 100;
	int window_count = pData->window_count;
	double window_height = pData->window_height / 100;
	double window_width = pData->window_width / 100;
	int door_count = pData->door_count;
	double door_height = pData->door_height / 100;
	double door_width = pData->door_width / 100;
	double layer_thickness = pData->layer_thickness;
	double consumption = pData->consumption;


	double room_square = room_length * room_height * 2 + room_width * room_height * 2 + room_length * room_width;
	double holes_square = window_count * window_height * window_width + door_count * door_height * door_width;
	double overall_square = room_square - holes_square;

	double result = ceil(overall_square * layer_thickness * consumption);

	printf("Считаем...\n");
	printf("Вам понадобится %.2lf кг штукатурки.\n", result);

	continueRequest(pData);

	return 0;
}

// Функция для повторного использования программы без необходимости ее перезапуска.
int continueRequest(building_data *pData)
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
		saveBuildingData(pData);
		printf("Введенные ранее значения сохранены!\n");
		printf("Завершение работы...\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("Введенные ранее значения сохранены!\nИх можно изменить используя меню!\n");
		programMenu(pData);
	}

	return 0;
}

// Функция для сохранения введенных данных в файл.
int saveBuildingData(building_data *pData)
{
	FILE* file;
	const char* filename = FILE_NAME;

	file = fopen(filename, "w");
	if (file == NULL)
	{
		printf("Не удалось открыть или создать файл.");
		return -1;
	}

	fprintf(file, "%s\n", "Длина комнаты (см):");
	fprintf(file, "%.0lf\n", pData->room_length);
	fprintf(file, "%s\n", "Ширина комнаты (см):");
	fprintf(file, "%.0lf\n", pData->room_width);
	fprintf(file, "%s\n", "Высота комнаты (см):");
	fprintf(file, "%.0lf\n", pData->room_height);
	fprintf(file, "%s\n", "Количество окон:");
	fprintf(file, "%.0d\n", pData->window_count);
	fprintf(file, "%s\n", "Высота окон (см):");
	fprintf(file, "%.0lf\n", pData->window_height);
	fprintf(file, "%s\n", "Ширина окон (см):");
	fprintf(file, "%.0lf\n", pData->window_width);
	fprintf(file, "%s\n", "Количество дверей:");
	fprintf(file, "%.0d\n", pData->door_count);
	fprintf(file, "%s\n", "Высота дверей (см):");
	fprintf(file, "%.0lf\n", pData->door_height);
	fprintf(file, "%s\n", "Ширина дверей (см):");
	fprintf(file, "%.0lf\n", pData->door_width);
	fprintf(file, "%s\n", "Толщина слоя штукатурки (мм):");
	fprintf(file, "%.2lf\n", pData->layer_thickness);
	fprintf(file, "%s\n", "Расход штукатурки на 1 м2");
	fprintf(file, "%.2lf\n", pData->consumption);

	fclose(file);

	return 0;
}
