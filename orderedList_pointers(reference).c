#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node {
	int element;
	struct Node *link;
}Node;

void SelectChoice(int ch);
Node* CreateNode(int e);
void InsertNode(int e);
void RemoveNode(int e);
void DisplayList();

Node* head = NULL;
Node* start = NULL;

int main() {
	int choice;
	printf("============================================");
	printf("\n    ORDERED LIST - POINTERS IMPLEMENTATION");
	printf("\n      1- INSERT  2- DELETE  0- EXIT\n");
	printf("============================================\n");
	do {
		printf("\nWhat do you want to do? ");
		scanf("%d", &choice);
		SelectChoice(choice);                                               //function for choosing a choice
	} while (choice != 0);


}

void SelectChoice(int choice) {
	int element;

	// Go through choices
	switch (choice) {
	case 0: printf("\n THANK YOU!!");
		break;
	case 1: // Insert a element into list.
		printf("\n============================================\n");
		printf("\n Insert element: ");
		scanf("%d", &element);
		InsertNode(element);
		break;
	case 2: // Remove a element into list.
		printf("\n============================================\n");
		printf("\n Remove element: ");
		scanf("%d", &element);
		if (start != NULL) {
			RemoveNode(element);
		}
		else {
			printf("============================================\n");
			printf("!!! LIST IS EMPTY !!!\n");
			printf("============================================");
		}
		break;
	default: // If the choice elementted was not predefined.
		printf(" Choice is inavlid!\n");
		break;
	}
}



Node* CreateNode(int element) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->element = element;
	node->link = NULL;

	return node;
}

void InsertNode(int element) {
	Node* node = (Node*)malloc(sizeof(Node));
	node = CreateNode(element);

	if (start == NULL) {
		start = node;
		head = node;
	}

	Node* pointer = start;
	while (pointer != NULL) {
		if (element < pointer->element) {
			if (pointer == start) {
				node->link = pointer;
				start = node;
				break;
			}
			else {
				node->link = pointer;
				Node* temp = start;

				while (temp->link != pointer) {
					temp = temp->link;
				}

				temp->link = node;
				break;
			}
		}
		else if (pointer->link == NULL) {
			head->link = node;
			head = head->link;
			head->link = NULL;
			break;
		}
		pointer = pointer->link;
	}
	printf("============================================\n");
	printf(" %d is now inserted\n", element);
	DisplayList();
}

void RemoveNode(int element) {
	Node* pointer = start;
	Node* temp1;
	while (pointer != NULL) {
		if (element == pointer->element) {
			if (pointer == start) {
				start = pointer->link;
			}
			else {
				Node* temp = start;

				while (temp->link != pointer) {
					temp = temp->link;
				}

				if (pointer->link == NULL) {
					temp->link = NULL;
					head = temp;
				}
				else {
					temp->link = pointer->link;
				}
			}
		}

		pointer = pointer->link;
	}
	printf("============================================\n");
	printf(" %d is removed from the list\n", element);
	DisplayList();
}

void DisplayList() {
	Node *temp = start;
	if (temp == NULL) {
		printf("!!! List is empty !!!");
		printf("============================================\n");
	}
	else {
		printf(" List: ");
		while (temp != NULL) {
			printf("[ %d ] ", temp->element);
			temp = temp->link;
			if (temp != NULL) {
				printf(", ");
			}
		}
		printf("\n============================================\n");
	}

	printf("\n");
}