#include<stdio.h>
#include<malloc.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "russian");//русский язык
	int n, pnt = 0, tnp = 1, a = 0, b = 0;
	char* ms, s;
	printf("Введите длинну\n");
	scanf_s("%d", &n);//ввод длинны строки
	n += 1;
	ms = (char*)malloc(sizeof(char) * n); // выделение памяти для дин. одномерного массива
	printf("Введите последовательность символов:\n");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%c", &ms[i]);// ввод строки
	}
	if (ms[1] == ' ')// проверка на пробел с начала строки
	{
		for (int i = 1; i < n; i++)
		{
			if (ms[i] == ' ')
			{
				pnt += 1;// наращивание счетчика
			}
			else
				if (ms[i] != ' ')
				{
					break;
				}
		}
	}
	if (ms[1] == ' ')// после нахождения кол-ва пробелов в начале убираем их
	{
		for (int i = 1; i < n; i++)
		{
			ms[i] = ms[i + pnt];
		}
		n -= pnt;
	}
	while (ms[n - 1] == ' ')
	{
		n--;
	}
	while (tnp == 1)// прохождению по ост. массиву
	{
		a = 0;
		for (int i = 0; i < n; i++)
		{
			if (ms[i] == ' ')
			{
				b += 1;// счетчк на пробелы в центральной части
			}
			else
			{
				b = 0;
			}
			if (b >= 2)
			{
				pnt = i;
				for (; pnt - b < n; pnt++)
				{
					ms[pnt] = ms[pnt + 1]; //убирание пробелов так, чтобы оставался один между группами символов
				}
				n--;
			}
		}
		for (int i = 0; i < n; i++) //цикл для конца строки
		{
			if (ms[i] == ' ')
			{
				a += 1;
			}
			else
			{
				a = 0;
			}
			if (a >= 2)
			{
				tnp = 1;
				break;
			}
			else
			{
				pnt = 0;
			}
		}
		if (a == 0)
		{
			break;
		}
	}
	printf("Преобразованная строка:");// вывод остатка строки 
	for (int i = 0; i < n; i++)
	{
		printf("%c", ms[i]);
	}
	return 0;
}
