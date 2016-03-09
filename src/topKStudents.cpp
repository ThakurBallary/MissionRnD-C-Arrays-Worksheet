/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct student {
	char name[10];
	int score;
};

int min(struct student **result, int K) {
	int s = 0;
	for (int i = 1; i < K; i++) {
		if (result[i]->score < result[s]->score) {
			s = i;
		}
	}
	return s;
}

struct student ** topKStudents(struct student *students, int len, int K) {
	if (students != NULL && len > 0 && K > 0) {
		if (K > len) {
			K = len;
		}
		struct student **result = (struct student**) malloc(sizeof(struct student*) * K);
		int i;
		for (i = 0; i < K; i++) {
			struct student *temp = (struct student*) malloc(sizeof(struct student));
			result[i] = temp;
			*temp = students[i];
		}
		int s = min(result, K);
		for (i = K; i < len; i++) {
			if (students[i].score > result[s]->score) {
				*result[s] = students[i];
				s = min(result, K);
			}
		}
		return result;
	}
	return NULL;
}
