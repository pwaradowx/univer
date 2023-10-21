#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

// Функуция для запроса у пользователя на продолжение и проверки корректности принимаемого значения.
char continue_request()
{
	char ans = '0';
	bool correct_val = ans == 'y' || ans == 'n';

	while (!correct_val)
	{
		printf("Желаете продолжить? (y/n): ");

		scanf("%c", &ans);

		correct_val = ans == 'y' || ans == 'n';

		if (!correct_val) 
		{ 
			printf("Введено некорректное значение!\n");
		}
	}

	return ans;
}

// Функция интерфейса для ознакомления пользователя с функционалом программы.
void welcome_menu()
{
	printf("Добро пожаловать!\n");
	printf("Эта программа предназначена для расчета количества смеси для штукатурки для комнаты.\n");
	printf("Ниже приведен список команд и их коды.\n");
	printf("1 - Ввести общую площадь потолка и стен\n");
	printf("2 - Ввести общую площадь проемов в комнате\n");
	printf("3 - Выход\n");
	
	continue_request();

}

void main()
{
	setlocale(LC_ALL, "Russian");

	welcome_menu();

}
