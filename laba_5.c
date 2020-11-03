#include<stdio.h>
#include<locale.h>
#include<math.h>
#define N 100
#define L 100

int main()
{
	setlocale(LC_ALL, "rus");
	int mas[N][L], l, n,max=0,a=0,b=0,i,j,g=0,kl=0;
	printf("Введите кол-во строк не более %3d\n", N - 1);                                       // ввод кол-ва эл. массива
	scanf_s("%d", &n);
	printf("Введите кол-во столбцов не более %3d\n", L - 1);                                    // ввод кол-ва эл. массива
	scanf_s("%d", &l);
	for (i = 0; i < n; i++)                                                                     // заполнение двумерного массива
	{
		for (j = 0; j < l; j++)
		{
			printf("Элемент [%d][%d]= ", i+1, j+1);
			scanf_s("%d", &mas[i][j]);
		}
	}
	max = mas[0][0];
	printf("Ваша матрица");
	for (i = 0; i < n; i++)                                                                     // вывод двумерного массива в виде матрицы
	{
		printf("\n");
		for (j = 0; j < l; j++)
		{
			printf("%4d",mas[i][j]);
		}
	}
	if (l != n)                                                                                 // проверка матрицы на квадратичность(если матрица не квадратная главной диагонали нет)
	{
		printf("\nМатрица не квадратная, главной диагонали нет");
		return 0;
	}
	for (i = 0; i < n; i++)                                                                     // поиск максимального эл-та на главной диагонали и его координат
		for (j = 0; j < l; j++)
		{
			if (i == j && mas[i][j] > max )
			{
				max = mas[i][j];
				a = i;
				b = j;
			}
		}
		printf("\nМаксимальный элемент равен %d ; его координаты [%d][%d]",max,a+1,b+1);
	for (i = 0; i < n; i++)                                                                     // поиск эл-та равного максимального под главной диагоональю
		for (j = 0; j < l; j++)
		{
			if (i > j && mas[i][j] == max)
			{
					a = i;
					b = j;
					kl = 1;
					printf("\nЭлемент равный максимальному на главной диагонали присутсвует ниже главной диаогонали; его координаты [%d][%d]",a+1,b+1);
			}
		}
	if (kl != 1)
		printf("\nЭлемента равного максимальному на главной диагонали нет ниже главной диаогонали");
	return 0;
}
