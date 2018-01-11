/*******************************************************
Programmer: 	Fretzel Sanchez
Title: 			Student Tracker
Date:			December 12, 2017
Course:			CPE 76 iOS Development
*******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char fname[10][20], lname[10][20];
int i = 0;

bool classFull(){
	if (i<10){
		return 0;
	}
	return 1;
}

void enrollStudent(){
	fflush(stdin);
	printf("Enter First Name: ");
	gets(fname[i]);
	printf("Enter Last Name: ");
	gets(lname[i]);
	i++;
}

void printClassList(){
	int count;
	
	for (count = i-1; count>=0; count--){
		printf("%s, %s\n", lname[count], fname[count]);
	}
}

void sortList(){
	int x, y;
	char tempFirst[20], tempLast[20];
	
	for (x=0; x<i; x++){
		for (y=0; y<i; y++){
			if (strcmp(lname[y], lname[y+1]) < 0){
				strcpy(tempLast, lname[y]);
				strcpy(tempFirst, fname[y]);
				strcpy(lname[y], lname[y+1]);
				strcpy(fname[y], fname[y+1]);
				strcpy(lname[y+1], tempLast);
				strcpy(fname[y+1], tempFirst);
			}
		}
	}

}

void selection(int num){
	switch(num){
		case 0: exit(0);
		case 1: if (!classFull()){
					enrollStudent();
				} else {
					printf("Class is full.\n");
				}
				break;
		case 2: printClassList();
				break;
		case 3: sortList();
				printClassList();
				break;
		default: printf("Invalid key.\n\n");
	}
}

int main(){
	int choice;
	while (1){
		printf("--------------------\n");
		printf("STUDENT TRACKER\n");
		printf("--------------------\n");
	
		printf("[1]Enroll student\n");
		printf("[2]View Class List\n");
		printf("[3]Sorted Class List\n");
		printf("[0]Exit\n");
		
		printf("Select a transaction: ");
		scanf("%d", &choice);
		selection(choice);
	}
	return 0;
}
