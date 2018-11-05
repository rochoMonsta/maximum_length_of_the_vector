#include <stdio.h>
#include <stdlib.h>
#define x 6
#define y 2

void clear()
{
	system("cls"); 
}

void feel(int masuv[][y])
{
	printf("Enter your vectores:\n");
	for (int i=0; i<x; i++)
	{
		for (int j=0; j<y; j++)
		{
			printf("%d.%d : ", i, j);
			scanf("%d", &masuv[i][j]);
		}
	}
}

void scalar_product(int masuv1[][y], int masuv2[][x])
{
	int vector_scal, num, len_x, len_y;
	for (int i = 0; i < x; i++)
	{
		masuv2[i][i] = 0;
		for (int j = i+1; j < x; j++)
		{
			num = 0;
			vector_scal = 0;
			len_x = masuv1[i][num] * masuv1[j][num];
			len_y = masuv1[i][num+1] * masuv1[j][num+1];
			vector_scal = len_x + len_y;
			masuv2[i][j] = vector_scal;
			masuv2[j][i] = vector_scal;
		}
	}
}


void print_mas_numbers(int masuv[][y])
{
	printf("    x   y  \n");
	printf("\n");
	for (int i = 0; i < x; i++)
	{
		printf("%d) ", i+1);
		for (int j = 0; j < y; j++)
		{
			printf(" %d ", masuv[i][j]);
		}
		printf("\n");
	}
}

int max_vector(int masuv[][x])
{
	int max = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (masuv[i][j]>max)
			{
				max = masuv[i][j];
			}
			else
			{
				max = max;
			}
		}
	}
	return max;
}

void find_max_index(int masuv[][x], int max, int rc[][y])
{
	int numb_1 = 0, numb_2 = 0, rocho = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (masuv[i][j] != max)
			{
				continue;
			}
			else
			{
				numb_1 = i, numb_2 = j;
				break;
			}
		}
	}
	printf("The largest length of the vector between : %d and %d\n", numb_1+1, numb_2+1);
	for (int z = 0; z < y; z++)
	{
		rocho = rc[numb_1][z];
		rc[numb_1][z] = rc[numb_2][z];
		rc[numb_2][z] = rocho;
	}
}


int main(void)
{
	int mas[x][y];
	int mass[x][x];
	feel(mas);
	clear();
	scalar_product(mas, mass);
	print_mas_numbers(mas);
	int max = max_vector(mass);
	find_max_index(mass, max, mas);
	print_mas_numbers(mas);
	return 0;
}


