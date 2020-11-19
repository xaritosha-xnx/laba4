#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include<locale.h>

int main() 
{
	setlocale(LC_ALL,"russian");// русский язык
	int *p1, n, max, mas[2], pnt = 0;
	printf("Введите размер квадратичной матрицы\n");
	scanf_s("%d", &n); 
	p1 = (int*)malloc(sizeof(int) * n * n); // инициализация двумерного массива(динамического)
	printf("\nВведите элементы матрицы\n");
	for (int i = 0; i < n; i++) //ввод элементов
	{
		for (int m = 0; m < n; m++) 
		{
			scanf_s("%d", p1 + i * n + m); 
		}
	}
	system("CLS"); 
	printf("Исходная матрица: \n");
	for (int i = 0; i < n; i++)// вывод матрицы
	{
		for (int m = 0; m < n; m++)
		{
			printf("%2d", *(p1 + i * n + m));
		}
		printf("\n");
	}
	max = *(p1 + 0 * n + 0); // изначально за макс. по модулю беру 1-е число
	for (int i = 0; i < n; i++) 
	{
		for (int m = 0; m < n; m++) 
		{
			if (abs(max) < abs(*(p1 + i * n + m)) || abs(max) == abs(*(p1 + i * n + m)))// определение макс. числа по модулю и запоминание его координат
			{
				max = *(p1 + i * n + m);                                               
				mas[0] = i; 
				mas[1] = m; 
			}
		}
	}
	printf("Измененная матрица: \n");
	for (int i = 0; i < n; i++) // вывод измененнной матрицы
	{
		if (i == mas[0]) 
		{
			pnt = 1; 
		}
		for (int m = 0; m < n; m++) 
		{
			if (i == mas[0] || m == mas[1]) 
			{
				continue;
			}
			printf("%2d ", *(p1 + i * n + m));
		}
		if (pnt == 1)
		{ 
			pnt = 0; 
		}
		else
		{
			printf("\n");
		}
	}
	return 0;
}
