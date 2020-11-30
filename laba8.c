#include<stdio.h>
#include<malloc.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	setlocale(LC_ALL, "russian");//русский язык
	int n, m, a = 0, b = 0, c = 0, d = 0,e=0,f=0;
	char** ms;
	printf("Введите кол-во строк\n");
	scanf_s("%d", &n);//ввод кол-ва строк
	n++;
	ms = (char**)calloc(n, sizeof(char*)); // выделение памяти для массива строк
	printf("Введите кол-во символов в строке\n");
	scanf_s("%d", &m);//ввод кол-ва символов в строке
	for (int i = 0; i < n; i++)
		ms[i] = (char*)calloc((m + 1), sizeof(char)); // выделение памяти для строки
	printf("Введите текст (длина строки не больше %d , строк не больше %d, перед переходом на новую строку ставить пробел):\n", m, n - 1);
	for (int i = 0; i < n; i++) //инициализация массива строк
	{
		gets(ms[i]);
	}
	system("CLS");
	for (int i = 0; i < n; i++)   //цикл для поиска кол-ва групп знаков через триггеры
	{
		for (int j = 0; j < m; j++)
		{
			if (ms[i][j] == '*' || ms[i][j] == '+' || ms[i][j] == '-')
			{
				a = 1;
			}
			else if (a == 1)
			{
				a = 0;
				b += 1;
			}
		}
	}
	for (int i = 0; i < n; i++) // цикл для поиска групп букв ерез триггеры
	{
		for (int j = 0; j < m; j++)
		{
			if (ms[i][j] >= 'a' &&  ms[i][j] <= 'z')		
			{
				c = 1;
			}
			else if (c == 1)
			{
				c = 0;
				d += 1;
			}
		}
	}
	for (int i = 0; i < n; i++) // цикл для поиска групп чисел через триггеры
	{
		for (int j = 0; j < m; j++)
		{
			if (ms[i][j] >= '0' && ms[i][j] <= '9')
			{
				e = 1;
			}
			else if (e == 1)
			{
				e = 0;
				f += 1;
			}
		}
	}
	printf("Ваш текст:");// вывод текста
	for (int i = 0; i < n; i++)
	{
		puts(ms[i]);
	}
	printf("\nКол-во групп знаков: %d Кол-во групп букв: %d Кол-во групп чисел: %d",b,d,f);// вывод кол-ва групп
	if (b > d)
		printf("\nГрупп знаков больше, чем групп букв"); //ответ
	else
		printf("\nГрупп букв больше, чем групп знаков");
	return 0;
}
