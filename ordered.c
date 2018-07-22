#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int count = 0;

int checkListFull(){
	if(count == MAX)
		return 1;
	return 0;
}

void addListItem(int list[], int item){
	int i, j, temp, loc, temp2, max = 0, min = 0;;
	
	if(count == 0){
		list[count] = item;
	}
	else if(count == 1){
		if(list[count-1] > item){
			temp = list[count-1];
			list[count-1] = item;
			list[count] = temp;
		}
		else{
			list[count] = item;
		}
	}
	else{
		max = item;
		min = item;
		for(j=0; j<count; j++){
			if(list[j] > max){
				max = list[j];
			}
			if(list[j] < min){
				min = list[j];
			}
			if((list[j] < item) && (list[j+1] > item)){
				loc = j+1;
			}
		}
		
		//insertion
		if(min == item){
			loc = 0;
		}
		if(max == item){
			loc = count;
		}
		for(i=count; i>=loc; i--){
			list[i] = list[i-1];
			if(i==loc){
				list[i] = item;
			}
		}
	}
	count++;
}

void removeListItem(int list[], int item){
	int i, j, temp;
	
	for(i=0; i<count; i++){
		if(item == list[i]){
			for(j=i+1; j<count; j++){
				temp = list[j];
				list[j] = list[j-1];
				list[j-1] = temp;
			}
			count--;
			break;
		}
	}
	
}

void display(int list[]){
	int i;
	for(i=0; i<count; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
}

main(){
	int item, list[MAX], i, choice;
	
	while(1){
		printf("Choice\n");
		printf("[1] add\n");
		printf("[2] delete\n");
		printf("[3] display\n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				if(!checkListFull()){
					printf("Enter item: ");
					scanf("%d", &item);
					
					addListItem(list, item);
				} else {
					printf("List is full");
				}
				break;
			case 2:
				printf("Enter item: ");
				scanf("%d", &item);
				
				removeListItem(list, item);
				break;
			case 3:
				display(list);
				break;
			default:
				printf("invalid");
		}	
	}		
}
