#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node *ptr;
ptr head, temp, temp1;

int count = 0;

int isEmpty(){
	if (head == NULL){
		return 1;
	}	
	return 0;
}

//void checkSize(){
//	temp = head;
//	while(temp->next != NULL){
//		count++;
//	}
//}
void insertFront(int item){
	temp = malloc(sizeof(struct node));
	temp->data = item;
	temp->next = head;
	head = temp;
}

void insertEnd(int item){
	temp1 = malloc(sizeof(struct node));
	temp = head;
	temp1->data = item;
	if (temp == NULL){
		temp1->data = item;
		temp1->next = head;
		head = temp1;
	} else {
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp1->next = temp->next;
		temp->next = temp1;
	}
}

void insertNth(int item, int pos){
	int i;
	temp = head;
	temp1 = malloc(sizeof(struct node));
	temp1->data = item;
	if (temp == NULL && pos != 1){
		printf("Invalid. List is empty.\n");
		return;
	} 
	else if (pos == 1){
		temp1->next = head;
		head = temp1;
	} else {
		for (i=1; i<pos-1;i++){
			temp = temp->next;
		}
		temp1->next = temp->next;
		temp->next = temp1;
	}		
}

void insertItem(int item){
	temp = head;
	int counter = 0;
	
	if (isEmpty()){
		insertFront(item);
		count++;
	}
	else if(count == 1){
		if(temp->data > item){
			insertFront(item);
		}
		else{
			insertEnd(item);
		}
		count++;
	}
	else {	
		int min = item;
		int max = item;
		while (temp->next != NULL){
			
			if (temp->data > max){
				max = temp->data;
			}
			if (temp->data < min){
				min = temp->data;
			}
			if((temp->data < item) && (temp->next->data > item)){
				insertNth(item, counter);
			}
			temp = temp->next;
			counter++;
		}
		
//		if (max == item){
//			insertEnd(item);
//		}
//		if (min == item){
//			insertFront(item);
//		}
		
		count++;
	}
}

void printList(){
	
	temp = head;
	if (temp == NULL){
		printf("List is empty.\n");
	} else {
		printf("Linked List: \n");
		while (temp != NULL){
			printf("%d ", temp->data);
			temp = temp->next;
	}
	}
	
	printf("\n");
}

int main(){
	head = NULL;
	char choice;
	int data;
	while (1){
		fflush(stdin);
		printf("---------ORDERED LIST--------\n");
		printf("[1] Insert an Item\n");
		printf("[2] Remove an Item\n");
		printf("[3] Head of List\n");
		printf("[4] Display Sorted List\n");
		printf("[0] Exit\n");
		printf("Choose a task.\n");
		scanf("%c", &choice);
		switch(choice){
			case '1':
				system("cls");
				printf("Input data: ");
				int item;
				scanf("%d", &item);
				insertItem(item);
				printList();
				break;
			
//			case '2':
//				system("cls");
//				break;
//				
//			case '3': 
//				system("cls");
//				break;
			
			case '4': 
				system("cls");
				printList();
				break;
			
			default:
				system("cls");
				printf("Invalid key. Try again.\n");
				break;
		}
	}
}
