#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * counting sort algorithm
 * @array: Array of integers to be sorted
 * @size: Amount of elements in array
 */
void counting_sort(int *array, size_t size)
{
	int i, max;
	int *count, *result;

	if (!array || size < 2)
		return;

	max = array[0];
	i = 1;
	while (i < (int)size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}

	count = calloc((max + 1), sizeof(int));
	if (!count)
		return;

	i = 0;
	while (i < (int)size)
	{
		count[array[i]]++;
		i++;
	}

	i = 1;
	while (i <= max)
	{
		count[i] += count[i - 1];
		i++;
	}
	print_array(count, max + 1);

	result = malloc(sizeof(int) * size);
	if (!result)
	{
		free(count);
		return;
	}

	i = (int)size - 1;
	while (i >= 0)
	{
		result[count[array[i]] - 1] = array[i];
		count[array[i]]--; /* Needed to handle identical values */
		i--;
	}

	i = 0;
	while (i < (int)size)
	{
		array[i] = result[i];
		i++;
	}
	free(count);
	free(result);
}
