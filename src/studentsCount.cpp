
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

void compare(int *Arr, int i, int score, int *lessCount, int *moreCount) {
	if (Arr[i] < score) {
		(*lessCount)++;
	}
	else if (Arr[i] > score) {
		(*moreCount)++;
	}
}

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	*lessCount = 0;
	*moreCount = 0;
	if (Arr == NULL || len < 1) {
		return NULL;
	}
	int i = 0, j = len - 1;
	while (i < j) {
		// comparing from front 
		compare(Arr, i, score, lessCount, moreCount);
		i++;
		// comparing from back
		compare(Arr, j, score, lessCount, moreCount);
		j--;
	}
	// comparing middle element
	if (i == j) {
		compare(Arr, i, score, lessCount, moreCount);
	}
	return NULL;
}
