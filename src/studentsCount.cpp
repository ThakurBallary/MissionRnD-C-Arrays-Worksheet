
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

int binarySearhScore(int *Arr, int len, int score) {
	int low = 0;
	int high = len - 1;
	while (low < high) {
		int mid = (low + high) / 2;
		if (Arr[mid] == score) {
			return mid;
		}
		else if (mid > 0 && Arr[mid - 1] < score && Arr[mid + 1] > score) {
			return mid;
		}
		else if (Arr[mid] < score) {
			low = mid + 1;
		}
		else {			
			high = mid - 1;
		}
	}
	if (Arr[low] == score) {
		return low;
	}
	else if (score < Arr[low]) {
		return -2;
	}
	else {
		return -1;
	}
}

int binaryLowCount(int *Arr, int low, int high, int score) {
	if (Arr[0] >= score) {
		return 0;
	}
	int end = high;
	while (low < high) {
		int mid = (low + high) / 2;
		if (mid > 0 && Arr[mid] == score && Arr[mid - 1] < score) {
			return mid;
		}
		else if (Arr[mid] < score) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	if (Arr[low] >= score) {
		return low;
	}
	else {
		return low + 1;
	}
}

int binaryHighCount(int *Arr, int low, int high, int score) {
	if (Arr[high] <= score) {
		return 0;
	}
	int end = high;
	while (low < high) {
		int mid = (low + high) / 2;
		if (mid < end && Arr[mid] == score && Arr[mid + 1] > score) {
			return end - mid;
		}
		else if (Arr[mid] <= score) {
			low = mid + 1;
		}
		else {
			high = mid - 1;			
		}
	}
	if (Arr[low] <= score) {
		return end - low;
	}
	else {
		return low + 1;
	}
}

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	*lessCount = 0;
	*moreCount = 0;
	if (Arr == NULL || len < 1) {
		return NULL;
	}
	int i = binarySearhScore(Arr, len, score);
	if (i == -1) {
		*lessCount = len;
	}
	else if (i == -2) {
		*moreCount = len;
	}
	else {
		*lessCount = binaryLowCount(Arr, 0, i, score);
		*moreCount = binaryHighCount(Arr, i, len-1, score);		
	}
	return NULL;
}
