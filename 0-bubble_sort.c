#include "sort.h"

/**
 * bubble_sort - This sorts array of integers in ascending order
 * @array: This is the array pointer to the array of integers
 * @size: This is the size of the array
 *
 * Return: This returns the sorted array of integers
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	int swapped, temp;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				for (k = 0; k < size; k++)
					printf("%d ", array[k]);
				printf("\n");
			}
		}

		if (swapped == 0)
			break;
	}
}
