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

	for (x = 0; x < size - 1; x++)
	    {
		for (y = 0; y < size - x - 1; y++)
		    {
			if (array[y] > array[y + 1])
				{
					temp = array[y + 1];
					array[y + 1] = array[y];
					array[y] = temp;
					swap = 1;
				}
				print_array(array, size);
		    }
			if (swap == 0)
				break;
	    }
}
