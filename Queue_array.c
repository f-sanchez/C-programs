#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 5        //set max size

int rear = -1; //aka tail
int front = -1; //aka head

				//queue empty
int isEmpty() {
	return((front) < 0);
}

//queue full
int isFull(int queue[]) {
	return (rear == SIZE - 1); //returns true (1) if full
}

//add item to queue
void enqueue(int queue[], int item) {
	if (isEmpty()) {
		front++;
	}

	if (rear == SIZE - 1) {
		printf("Queue overflow.\n\n");
		return;
	}
	else {
		queue[++rear] = item;
		printf("element added to queue: %d\n\n", item);
	}
}

//remove item from queue
int dequeue(int queue[]) {
	if (isEmpty()) {
		return -1;
	}
	
	int item1 = queue[front];
	
	if (front == rear) {
		front = rear = -1;
	}
	else {
	    int i;
	    for (i=front; i<rear; i++){
	        queue[i] = queue[i+1];
	    }
	    rear--;
	}
	return item1;
}

//get front of queue
int getFront(int queue[]) {
	return queue[front];
}

//get rear of queue
int getRear(int queue[]) {
	return queue[rear];
}

void display(int queue[]) {
	int i;
	if (isEmpty()) {
		printf("Queue empty.\n");
	}
	else {
		printf("Queue: ");
		for (i = front; i <= rear; i++) {
			if (i == rear) {
				printf("[%d] =>%d \n", i, queue[i]);
			}
			else {
				printf("[%d] =>%d, ", i, queue[i]);
			}
		}
	}
	printf("\n");
}

/*
int checkInput(char input) {
	int flag = 0;
	for (int i = 48; i <= 57; i++) {
		if (input == i) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		return 1;
	}
	else {
		return 0;
	}
}
*/


int main() {
	int queue[SIZE];

	while (1) {
		printf("--------QUEUE--------\n\n");
		printf("[1] enqueue\n");
		printf("[2] dequeue\n");
		printf("[3] get Front & Rear\n");
		printf("[4] display\n");
		printf("[0] Exit\n");
		printf("Please select a task: ");
		char choice;
		choice = getch();
//		printf("%c", getchar());
//		scanf("%c", &choice);
	/*	if (!(checkInput(choice))) {
			printf("error\n");
		}
		else {
			choice = choice - 48;

		}*/
		switch (choice) {
			case '1':
				system("cls");
				printf("Enter item: ");
				int item;
				scanf("%d", &item);
				enqueue(queue, item);
				display(queue);
				break;
			case '2':
				system("cls");
				printf("element dequeued: %d\n\n", dequeue(queue));
				display(queue);
				break;
			case '3':
				system("cls");
				if (isEmpty()) {
					printf("Queue empty.\n\n");
				}
				else {
					display(queue);
					printf("Front: %d\n", getFront(queue));
					printf("Rear: %d\n\n", getRear(queue));
				}
				break;
			case '4':
				system("cls");
				display(queue);
				break;
			case '0':
				exit(0);
			default:
				system("cls");
				printf("Please select a valid key.\n\n");
				break;
			}
	}
	return 0;
}
