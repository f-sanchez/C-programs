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
	
	for (count = i; count>=0; count--){
		printf("%s %s\n", fname[count], lname[count]);
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
		default: printf("Invalid key.\n\n");
	}
}

int main(){
	int choice;
	while (1){
		printf("STUDENT TRACKER\n");
	
		printf("[1]Enroll student\n");
		printf("[2]View Class List\n");
		printf("[0]Exit\n");
		
		printf("Select a transaction: ");
		scanf("%d", &choice);
		selection(choice);
	}
	return 0;
}
