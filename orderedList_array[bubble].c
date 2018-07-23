#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int count = 0;

int checkListFull() {
	if (count == MAX)
		return 1;
	return 0;
	
}

void addListItem(int list[], int item) {
	int i, j, temp;
	list[count] = item;
	count++;
	if (count > 0) {
		for (i = 0; i <= count; i++) {
			for (j = 1; j<count; j++) {
				if (list[j] < list[j - 1]) {
					temp = list[j];
					list[j] = list[j - 1];
					list[j - 1] = temp;
					
				}
				
			}
			
		}
		
	}
	
}

void removeListItem(int list[], int item) {
	int i, j, temp;
	
		for (i = 0; i<count; i++) {
		if (item == list[i]) {
			for (j = i + 1; j<count; j++) {
				temp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = temp;
				
			}
			
		}
		
	}
	count--;
	
}

void display(int list[]) {
	int i;
	for (i = 0; i<count; i++) {
		printf("%d ", list[i]);
		
	}
	printf("\n");
	
}

main() {
	int item, list[MAX], i, choice;
	
		while (1) {
		printf("Choice\n");
		printf("[1] add\n");
		printf("[2] delete\n");
		printf("[3] display\n");
		scanf("%d", &choice);
		
			switch (choice) {
			case 1:
				if (!checkListFull()) {
					printf("Enter item: ");
					scanf("%d", &item);
					
						addListItem(list, item);
					
				}
				else {
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