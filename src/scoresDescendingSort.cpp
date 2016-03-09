/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct student {
	char name[10];
	int score;
};

void mergeSort(struct student *, int, int);
void merge(struct student *, int, int, int);

void * scoresDescendingSort(struct student *students, int len) {
	if (students != NULL && len > 1) {
		int l = 0;
		int h = len - 1;
		mergeSort(students, l, h);
	}
	return NULL;
}

void mergeSort(struct student *students, int l, int h) {
	if (l < h) {
		int mid = (l + h) / 2;
		mergeSort(students, l, mid);
		mergeSort(students, mid + 1, h);
		merge(students, l, mid, h);
	}
}

void merge(struct student *students, int l, int mid, int h) {
	struct student *temp = (struct student*) malloc(sizeof(struct student) * (h - l + 1));
	int i = l;
	int j = mid + 1;
	int k = l;
	while (i <= mid && j <= h) {
		if (students[i].score >= students[j].score) {
			temp[k] = students[i];
			i++;
		}
		else {
			temp[k] = students[j];
			j++;
		}
		k++;
	}
	/* append remaining left elements */
	while (i <= mid) {
		temp[k] = students[i];
		k++;
		i++;
	}
	/* append remaining right elements */
	while (j <= h) {
		temp[k] = students[j];
		k++;
		j++;
	}
	/* copy sorted data */
	for (i = l, k = 0; i <= h; i++, k++) {
		students[i] = temp[k];
	}
	free(temp);
	temp = NULL;
}