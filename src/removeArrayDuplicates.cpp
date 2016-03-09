/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

int removeArrayDuplicates(int *Arr, int len)
{
	if (Arr != NULL && len > 0) {
		int i, j = 0, s = -1;
		for (i = 1; i < len; i++) {
			if (Arr[i] != Arr[j]) {
				int k = 0;
				while (k < j) {
					if (Arr[i] == Arr[k]) {
						if (s < 0) {
							s = i;
						}
						break;
					}
					k++;
				}
				if (k == j) {
					if (s != -1) {
						Arr[s] = Arr[i];
						s++;
					}
					j++;
				}
			}
			else {
				if (s < 0) {
					s = i;
				}
			}
		}
		return j + 1;
	}
	return -1;
}