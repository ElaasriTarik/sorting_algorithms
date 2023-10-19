#include "sort.h"

/**
 * bubble_sort - a bubble sort algorithm
 * @array: array of integers to sort
 * @size: size of the arry
 */

void bubble_sort(int *array, size_t size)
{
	size_t x;
	size_t y;
	int temp, swap;

	if (!array || !size)
		return;
	x = 0;
	while (x < size)
	{
		for (y = 0; y < size - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
		x++;
		if (swap == 0)
			break;
	}
}
