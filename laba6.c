#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include<locale.h>

int main() 
{
	setlocale(LC_ALL,"russian");// русский язык
	int *p1,*p2, n, max, mas[2],j=0,k=0;
	printf("Введите размер квадратичной матрицы\n");
	scanf_s("%d", &n); 
	p1 = (int*)malloc(sizeof(int) * n * n);
	p2 = (int*)malloc(sizeof(int) * (n-1) * (n-1));// инициализация двумерного массива(динамического)
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
	for (int i = 0; i < n; i++) // замена эл=тов на пересечении на 0 (исп. в качестве триггера)
	{
		for (int m = 0; m < n; m++) 
		{
			if (i == mas[0] || m == mas[1]) 
			{
				*(p1 + i * n + m) = 0;
			}
		}
	}
	printf("Измененная матрица: \n");
	for (int i = 0; i < n; i++)// перезаполнение массива
	{
		for (int m = 0; m < n; m++)
		{
			if (*(p1 + i * n + m) != 0)
			{
				*(p2 + j * (n - 1) + k) = *(p1 + i * n + m);
				k += 1;
				if (k == (n - 1))
				{
					k = 0;
					j += 1;
				}
			}
		}	
	}
	free(p1); // освобождение памяти
	for (int i = 0; i < (n-1); i++)// вывод матрицы
	{
		for (int m = 0; m < (n-1); m++)
		{
			printf("%2d", *(p2 + i * (n-1) + m));
		}
		printf("\n");
	}
	return 0;
}
