
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
		//printf("Front: %d\n", front);
		front++;
		//printf("Front: %d\n", front);
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

void dequeue(int queue[]) {
	if (isEmpty()) {
		printf("Queue empty.\n\n");
	}
	else if (front == rear) {
		printf("%d dequeued.\n\n", queue[front]);
		front = rear = -1;
	}
	else {
		printf("%d dequeued.\n\n", queue[front++]);
	}
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


int main() {
	int queue[SIZE];

	printf("--------QUEUE--------\n\n");
	while (1) {
		printf("[1] enqueue\n");
		printf("[2] dequeue\n");
		printf("[3] get Front & Rear\n");
		printf("[4] display\n");
		printf("[0] Exit\n");
		printf("Please select a task: ");
		char choice;
		scanf("%c", &choice);
		//choice = getch();
		if (!(checkInput(choice))) {
			printf("error\n");
		}


		switch (choice) {
		case 1:
			system("cls");
			printf("Enter item: ");
			int item;
			scanf("%d", &item);
			enqueue(queue, item);
			break;
		case 2:
			system("cls");
			dequeue(queue);
			break;
		case 3:
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
		case 4:
			system("cls");
			display(queue);
			break;
		case 0:
			exit(0);
		default:
			system("cls");
			printf("Please select a valid key.\n\n");
			break;
		}
	}
}


