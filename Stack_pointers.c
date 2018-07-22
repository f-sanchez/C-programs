#include <stdio.h>
#include <stdlib.h>
  
struct node {				//create a node struct containing the data and pointer to next
    int data;
    struct node *next;
};

typedef struct node node;	//create an alias for struct node

node *top;					//create pointer to top

void initialize(){
    top = NULL;				//empty stack
}

//add item to stack
void push(int item){
    node *temp;						
    temp = malloc(sizeof(node));	//allocate memory for temp the size of node
    temp->data = item;				
    temp->next = top;				
    top = temp;						//newly added node becomes top of stack
}

//remove item from stack
void pop(){
    node *temp;
    temp = top;						//set temp to top; top of stack is removed during pop
    top = top->next;				//new top equals the next of the previous top
    free(temp);						//empty temp/top of stack
}

int top_of_stack(){
    return top->data;
}

int isEmpty(){
    return top == NULL;
}

void print_stack(node *head){
    if(isEmpty()){
        printf("Stack empty.\n\n");
    } else {
        printf("\nStack:\tTop-> ");
        while (head != NULL){
            printf("%d-> ", head->data);
            head = head->next;
        }
        printf("NULL\n\n");
    }
}

int main(){
    initialize();
    char choice;
    while (1){
    	fflush(stdin);
    	printf("------------STACK------------\n\n");
        printf("Choose a task:\n");
        printf("[1] Push an item into Stack\n");
        printf("[2] Pop item from Stack\n");
        printf("[3] Return value of Top\n");
        printf("[4] Print items in Stack\n");
        printf("[0] Exit\n");
        scanf("%c", &choice);
        switch(choice){
            case '0': exit(0);
            
            case '1': 
				system("cls");
				printf("Input item: ");
                int item;
                scanf("%d", &item);
                push(item);
                print_stack(top);
                break;
                
            case '2': 
				system("cls");
				if(isEmpty()){
					printf("Stack underflow.\n\n");
				}
				else {
					pop();
					print_stack(top);
				}
                break;
                
            case '3': 
				system("cls");
				if (isEmpty()){
                    printf("Stack empty.\n\n");
                } else {
                    printf("Top of Stack: %d\n", top_of_stack());
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

