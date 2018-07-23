#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {				//create a node struct containing the data and pointer to next
	int data;
	struct node *next;
};

typedef struct node node;	//create an alias for struct node

node *head, *start, *newNode;

void initialize() {			//empty list
	head = NULL;			
	start = NULL;
}

int listEmpty() {
	return (head ==  NULL);
}

struct node* createNode(int item) {
	node *newNode = malloc(sizeof(node));		//allocate memory for newNode
	newNode->data = item;
	newNode->next = NULL;
	return newNode;
}

void insertNode(int item) {
	node* newNode = malloc(sizeof(node));
	newNode = createNode(item);

	if (start == NULL) {						//if list is empty, insertFront
		start = newNode;		
		head = newNode;
	}

	node* pointer = start;
	while (pointer != NULL) {					
		if (item < pointer->data) {				//if item less than currentNode->data
			if (pointer == start) {				//if pointer equals head, insertFront
				newNode->next = pointer;
				start = newNode;
				break;
			}
			else {								//else
				newNode->next = pointer;
				node* temp = start;

				while (temp->next != pointer) {		//traverse
					temp = temp->next;
				}

				temp->next = newNode;			//insert newNode
				break;
			}
		}
		else if (pointer->next == NULL) {		//if end node
			head->next = newNode;				//insertEnd
			head = head->next;
			head->next = NULL;
			break;
		}
		pointer = pointer->next;				//proceed to next node in the list
	}
}

//remove node from list
//implementation similar to insertNode, except 
//when item is found, pointer from previous node points to node of item to be removed
void removeNode(int item) {
	node* pointer = start;
	int flag = 0;								//flag set as 0
	while (pointer != NULL) {
		if (item == pointer->data) {
			flag = 1;							//item found
			if (pointer == start) {
				start = pointer->next;
			}
			else {
				node* temp = start;
				while (temp->next != pointer) {
					temp = temp->next;
				}
				if (pointer->next == NULL) {
					temp->next = NULL;
					head = temp;
				}
				else {
					temp->next = pointer->next;
					
				}
			}
			break;								//do not allow removal of multiple same number or once item is found, 
												//loop breaks, removing only one item
		}
		pointer = pointer->next;				//proceed to next node
	}

	if (!flag) {
		printf("Item not found. See ordered list and try again.\n");
	}
	else {
		printf("item removed: %d\n", item);
	}
	free(pointer);								//empty node of removed item
}

//print items in list
void display() {
	node *temp = start;
	if (listEmpty()) {
		printf("List is empty.\n");
	}
	else {
		printf("List: ");
		while (temp != NULL) {
			printf(" %d ->  ", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
	printf("\n");
}

//function to clean stdin
//note: fflush(stdin) shouldve worked but since im running visual studio,
//this function is what works
void flush_stdin(void) {
	int ch;
	do {
		ch = getchar();
	} while (ch != '\n' && ch != EOF);
}

//function to accept only integer
int checkInput() {
	int input;
	while (scanf("%d", &input) == 0) {					//if scanf failed to scan an integer; yields false
		printf("Input invalid. Please enter an integer.\n");
		flush_stdin();
	}
	return input;
}

int main() {
	initialize();
	int choice;
	int item;
	while (1) {
		printf("--------ORDERED LIST----------\n");
		printf("\t[pointers]\n");
		printf("-----------------------------\n\n");
		printf("[1] Add an item to List\n");
		printf("[2] Delete an item from List\n");
		printf("[3] Display Ordered List items\n");
		printf("[0] Exit\n");
		printf("Please select a task. ");
		char choice;
		scanf("%c", &choice);
		flush_stdin();
		switch (choice) {
		case '1':
			system("cls");
			printf("Enter item: ");
			item = checkInput();
			flush_stdin();
			insertNode(item);
			display();
			break;

		case '2':
			system("cls");
			if (!listEmpty()) {
				printf("Enter item: ");
				scanf("%d", &item);
				flush_stdin();
				removeNode(item);
			}
			display();
			break;

		case '3':
			system("cls");
			display();
			break;

		case '0':
			exit(0);

		default:
			system("cls");
			printf("Please select a valid key.\n\n");
		}
	}
	return 0;
}