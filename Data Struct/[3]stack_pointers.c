#include <stdio.h>
#include <stdlib.h>

struct node {				//create a node struct containing the data and pointer to next
	int data;
	struct node *next;
};

typedef struct node node;	//create an alias for struct node

node *top;					//create pointer to top

void initialize() {
	top = NULL;				//empty stack
}

//add item to stack
void push(int item) {
	node *temp;
	temp = malloc(sizeof(node));	//allocate memory for temp the size of node
	temp->data = item;
	temp->next = top;
	top = temp;						//newly added node becomes top of stack
}

//remove item from stack
void pop() {
	node *temp;
	temp = top;						//set temp to top; top of stack is removed during pop
	top = top->next;				//new top equals the next of the previous top
	free(temp);						//empty temp/top of stack
}

//get top of stack
int top_of_stack() {
	return top->data;
}

//check if stack is empty
int isEmpty() {
	return top == NULL;
}

//display items in stack
void print_stack(node *head) {
	if (isEmpty()) {
		printf("Stack empty.\n\n");
	}
	else {
		printf("\nStack:\tTop-> ");
		while (head != NULL) {
			printf("%d-> ", head->data);
			head = head->next;
		}
		printf("NULL\n\n");
	}
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
		//fflush(stdin);
		flush_stdin();
	}
	return input;
}

int main() {
	initialize();
	char choice;
	while (1) {
		//fflush(stdin);
		printf("------------STACK------------\n\n");
		printf("[1] Push an item into Stack\n");
		printf("[2] Pop item from Stack\n");
		printf("[3] Return value of Top\n");
		printf("[4] Print items in Stack\n");
		printf("[0] Exit\n");
		printf("Choose a task: ");
		scanf("%c", &choice);
		flush_stdin();
		switch (choice) {
		case '0': exit(0);

		case '1':
			system("cls");
			printf("Input item: ");
			int item;
			//scanf("%d", &item);
			item = checkInput();
			flush_stdin();
			push(item);
			print_stack(top);
			break;

		case '2':
			system("cls");
			if (isEmpty()) {
				printf("Stack underflow.\n\n");
			}
			else {
				pop();
				print_stack(top);
			}
			break;

		case '3':
			system("cls");
			if (isEmpty()) {
				printf("Stack empty.\n\n");
			}
			else {
				printf("Top of Stack: %d\n", top_of_stack());
				print_stack(top);
			}
			break;

		case '4':
			system("cls");
			print_stack(top);
			break;

		default:
			system("cls");
			printf("Invalid key. Try again.\n\n");
		}
	}
	return 0;
}
