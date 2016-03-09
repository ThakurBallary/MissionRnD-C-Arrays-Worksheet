/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void swap(int *Arr, int a, int b) {
	Arr[a] = Arr[a] + Arr[b];
	Arr[b] = Arr[a] - Arr[b];
	Arr[a] = Arr[a] - Arr[b];
}

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr != NULL && len > 0) {
		int i, l = len - 1;
		for (i = 0; i < l; i++) {
			if (Arr[i] > Arr[i + 1]) {
				int t = i + 1;
				while (t < len && Arr[i] > Arr[t]) {
					t++;
				}
				swap(Arr, i, t - 1);
				return NULL;
			}
		}
	}
	return NULL;
}