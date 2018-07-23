#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

typedef struct node* ptr;
ptr head, temp, temp1;

void insertFront(int data){
	temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = head;
	head = temp;
}

void insertEnd(int data){
	temp1 = malloc(sizeof(struct node));
	temp = head;
	temp1->data = data;
	if (temp == NULL){
		temp1->data = data;
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

void insertNth(int data, int pos){
	int i;
	temp = head;
	temp1 = malloc(sizeof(struct node));
	temp1->data = data;
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

void printList(){
	
	temp = head;
	printf("Linked List: \n");
	while (temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void deleteEnd(){
	temp = head;
	if (temp == NULL){
		printf("List is empty.\n");
	} else {
		while (temp->next != NULL){
			temp1 = temp;
			temp = temp->next;	
		}
		temp1->next = temp->next;
		free(temp);
	}
}

void deleteFront(){
	temp = head;
	
	if (temp == NULL){
		printf("List is empty.\n");
	} else {
		temp1 = temp->next;
		head = temp1;
		free(temp);
	}
}

void deleteNth(int pos){
	temp = head;
	int i;
	if (temp == NULL){
		printf("List is empty.\n");
	} 
	else if (pos ==1 ){
		deleteFront();
	} else {
		for (i=1; i<pos-1; i++){
			temp = temp->next;
		}
		temp1 = temp->next;
		temp->next = temp1->next;
		free(temp1);
	}
}

int main(){
	
	head = NULL;
	
	int choice, pos, data;
	while (1){
		printf("Choose a task: \n");
		printf("[0] Exit\n");
		printf("[1] insertFront\n");
		printf("[2] insertEnd\n");
		printf("[3] insertNth\n");
		printf("[4] deleteFront\n");
		printf("[5] deleteEnd\n");
		printf("[6] deleteNth\n");
		scanf("%d", &choice);
		
		switch (choice){
			case 0: exit(0);
			case 1: printf("Input data: ");
					scanf("%d", &data);
					insertFront(data);
					printList();
					break;
			case 2: printf("Input data: ");
					scanf("%d", &data);
					insertEnd(data);
					printList();
					break;
			case 3: printf("Input data: ");
					scanf("%d", &data);
					printf("Input position: ");
					scanf("%d", &pos);
					insertNth(data, pos);
					printList();
					break;
			case 4: deleteFront();
					printList();
					break;
			case 5: deleteEnd();
					printList();
					break;
			case 6: printf("Input position: ");
					scanf("%d", &pos);
					deleteNth(pos);
					printList();
					break;
			default: printf("Choice invalid.\n");
		}
	}
	return 1;
}