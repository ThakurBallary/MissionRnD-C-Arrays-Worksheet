#include "FunctionHeadersArrays1.h"
#include <stdio.h>

struct student {
	char name[10];
	int score;
};

int main(){

	int i;

	//Test Students Count
	int Arr[10] = { 1, 2, 2, 2, 2, 2, 2, 2, 2, 3 }, lessCount, moreCount;
	studentsCount(Arr, 10, 2, &lessCount, &moreCount);
	printf("%d %d\n", lessCount, moreCount);

	//Test sortedArrayInsertNumber
	int Arr2[3] = { 1, 4, 10 };
	int *newarray = sortedArrayInsertNumber(Arr2, 3, 2);
	for (i = 0; i < 4; i++) {
		printf("%d ", newarray[i]);
	}
	printf("\n");

	//Test sortedArrayPositionsChange
	int Arr3[5] = { 10, 40, 30, 20, 50 };
	sortedArrayPositionsChange(Arr3, 5);
	for (i = 0; i < 5; i++) {
		printf("%d ", Arr3[i]);
	}
	printf("\n");

	//Test scoresDescendingSort
	struct student students[3] = { { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } };
	scoresDescendingSort(students, 3);
	for (i = 0; i < 3; i++) {
		printf("%s: %d ", students[i].name, students[i].score);
	}
	printf("\n");

	//Test RemoveArraysDuplicates
	int Arr4[8] = { 1, 3, 3, 4, 2, 4, 1, 5 };
	int len = removeArrayDuplicates(Arr4, 8);
	for (i = 0; i < len; i++) {
		printf("%d ", Arr4[i]);
	}
	printf("\n");

	//Test topKStudents
	struct student students2[4] = { { "stud1", 40 }, { "stud2", 10 }, { "stud3", 20 }, { "stud4", 50 } };
	struct student **result = topKStudents(students2, 4, 3);
	for (i = 0; i < 3; i++) {
		printf("%d ", result[i]->score);
	}
	
	return 0;
}