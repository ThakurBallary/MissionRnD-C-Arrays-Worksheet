/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr != NULL && len > 0) {
		/*
		realloc is not working
		int *newArray = (int*) realloc(Arr, sizeof(int) * (len + 1));
		*/
		int *newArray = (int*)malloc((len + 1) * sizeof(int));
		int i = 0, k = 0;
		while (i < len) {
			if (num < Arr[i]) {
				newArray[k] = num;
				num = Arr[len - 1];
			}
			else {
				newArray[k] = Arr[i];
				i++;
			}
			k++;
		}
		if (k == len) {
			newArray[k] = num;
		}
		return newArray;
	}
	return NULL;
}