#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#define MAX 5

int count = 0;											//initialize count; list empty

														//check if list is full
int listFull() {
	if (count == MAX)
		return 1;
	return 0;
}

//check if list is empty
int listEmpty() {
	if (count == 0) {
		return 1;
	}
	return 0;
}

//add an item to list
void addListItem(int list[], int item) {
	list[count] = item;									//add item to list[count]
	count++;											//increment count after adding item
	if (count > 0) {									//if list is 
		int i, j;
		for (i = 0; i <= count; i++) {					//implements bubble sort; two loops to check every item in the list
			for (j = 1; j<count; j++) {					//with the item next to it
				if (list[j] < list[j - 1]) {			//compare adjacent items; if list[j] is less than list[j-1], 
					int temp = list[j];						//swap items
					list[j] = list[j - 1];
					list[j - 1] = temp;
				}
			}
		}
	}
}

//delete an item from list
void removeListItem(int list[], int item) {
	int i, j;
	int flag = 0;
	for (i = 0; i < count; i++) {							//traverse items in list from index0 - (count-1)
		if (item == list[i]) {							//if searched item is found
			flag = 1;
			for (j = i + 1; j < count; j++) {				//shift all items in the list to the left
				int temp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = temp;
			}
			count--;									//decrement count as one item is removed from the list
		}
	}
	if (flag == 0) {									//if item not found
		printf("Item not found. See ordered list and try again.\n");
	}
}

//display items in the list
void display(int list[]) {
	int i;
	if (listEmpty()) {
		printf("List is empty.\n\n");
	}
	else {
		printf("\nOrdered List: ");
		for (i = 0; i<count; i++) {							//scan all items in list
			if (i == count - 1) {
				printf("[%d] => %d", i, list[i]);
			}
			else {
				printf("[%d] => %d, ", i, list[i]);				//print item
			}
		}
		printf("\n\n");
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
	int list[MAX];

	while (1) {
		//fflush(stdin);
		printf("----------ORDERED LIST--------------\n\n");
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
			if (!listFull()) {
				printf("Enter item: ");
				int item;
				//scanf("%d", &item);
				item = checkInput();
				flush_stdin();
				addListItem(list, item);
			}
			else {
				printf("List is full.\n");
			}
			display(list);
			break;

		case '2':
			system("cls");
			if (!listEmpty()) {
				printf("Enter item: ");
				int item;
				scanf("%d", &item);
				flush_stdin();
				removeListItem(list, item);
			}
			display(list);
			break;

		case '3':
			system("cls");
			display(list);
			break;

		case '0':
			exit(0);

		default:
			system("cls");
			printf("Invalid key. Try again.\n\n");
			break;
		}
	}
	return 0;
}