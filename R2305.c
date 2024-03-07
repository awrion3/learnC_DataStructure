#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//5
//Write a C program to store information of students using structure.

typedef struct student {
	int id;
	char name[10];
} student;

int main(void) {

	student *p;
	int num;
	char temp[10];

	scanf("%d", &num);

	p = (student*)malloc(sizeof(student) * num);
	
	if (p == NULL) {
		printf("memory error!\n");
		return -1;
	}
	else {
		for (int i = 0; i < num; i++) {
			scanf("%s", temp);
			strcpy(p[i].name, temp);
			p[i].id = i + 1;

			printf("id: %d name: %s\n", p[i].id, p[i].name);
		}
	}
	
	free(p);
	return 0;
}