#include "Header.h"

// Соединение двух строк в одну
char* unification(char* a, char* b)
{
	int l1 = 0, l2 = 0;
	while (a[l1] != '\0')
	{
		l1++;
	}
	while (a[l2] != '\0')
	{
		l2++;
	}
	char* c = calloc(l1 + l2, sizeof(char));
	for (int i = 0; i < l1; i++) {
		c[i] = a[i];
	}
	for (int i = 0; i < l2; i++) {
		c[i + l1] = b[i];
	}
	c[l1 + l2] = '\0';
	return c;
}

// Преобразования строки в число
int ConvertToInt(char* s)
{
	int number = 0;
	int sign = 0; // знак числа числа 0 - положительное, 1 — отрицательное
	int i = 0;
	if (s[0] == '-')
	{
		sign = 1;
		i++;
	}
	while (s[i] != '\0')
	{
		number = number + (s[i] & 0x0F);
		number = number * 10;
		i++;
	}
	number = number / 10;
	if (sign == 1)
	{
		number = -number;
	}
	return(number);
}

// Функция преобразования числа в строку
char* ConvertToString(int a)
{
	int i = 0, k, l1 = 0;
	int sign = 0; // знак числа 0 - положительное, 1 — отрицательное
	if (a < 0)
	{
		sign = 1;
		a = -a;
		l1++;
	}
	int n1 = a;
	while (a > 0) // Определение колличества элементов для строки
	{
		a = a / 10;
		l1++;
	}
	char* str1 = calloc(l1, sizeof(char));
	a = n1;
	while (a > 0)
	{
		k = a % 10;
		a = a / 10;
		str1[i] = k | 0x30;
		i++;
	}
	if (sign == 1)
	{
		str1[i] = '-';
		i++;
	}
	i--;
	char* str2 = calloc(l1, sizeof(char));
	while (i >= 0) {
		str2[a] = str1[i];
		i--; a++;
	}
	str2[a] = '\0';
	return(str2);
}

int main(void)
{
	system("chcp 1251>nul");
	while (1)
	{
		int number;
		while (1)
		{
			printf("\nВыберите действие:\n1 - Найти сумму чисел\n2 - Найти разность чисел\n3 - Найти произведение чисел\n4 - Найти частное чисел\n5 - Объединить две строки\n6 - Преобразовать число в строку и строку в число\n7 - Завершить работу программы\n");
			scanf_s("%d", &number);
			if (number == 1 || number == 2 || number == 3 || number == 4 || number == 5 || number == 6 || number == 7) {
				break;
			}
			else
			{
				system("cls");
				printf("Введены некоректнные данные!!! Повторите ввод!");
			}
		}
		if (number == 1) {
			system("cls");
			int a, b;
			printf("Введите первое число: ");
			scanf_s("%d", &a);
			printf("Введите второе число: ");
			scanf_s("%d", &b);
			printf("Сумма элементов: %d\n", Summ(a, b));
			system("pause");
			system("cls");
		}
		if (number == 2) {
			system("cls");
			int a, b;
			printf("Введите первое число: ");
			scanf_s("%d", &a);
			printf("Введите второе число: ");
			scanf_s("%d", &b);
			printf("Разность элементов: %d\n", Rasn(a, b));
			system("pause");
			system("cls");
		}
		if (number == 3) {
			system("cls");
			int a, b;
			printf("Введите первое число: ");
			scanf_s("%d", &a);
			printf("Введите второе число: ");
			scanf_s("%d", &b);
			printf("Произведение элементов: %d\n", Prois(a, b));
			system("pause");
			system("cls");
		}
		if (number == 4) {
			system("cls");
			int a, b;
			printf("Введите первое число: ");
			scanf_s("%d", &a);
			printf("Введите второе число: ");
			scanf_s("%d", &b);
			printf("Частное элементов: %3.2f\n", Chast(a, b));
			system("pause");
			system("cls");
		}
		if (number == 5) {
			system("cls");
			char* a = "строка ";
			char* b = "символ";
			printf("%s\n", unification(a, b));
			system("pause");
			system("cls");
		}
		if (number == 6) {
			system("cls");
			char* s = "Привет";
			int num = ConvertToInt(s);
			printf("Число: %d", num);
			char* str = ConvertToString(num);
			printf("\nСтрока: %s\n", str);
			system("pause");
			system("cls");
		}
		if (number == 7) {
			break;
		}
	}
	return 0;
}
