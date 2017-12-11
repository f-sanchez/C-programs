#include <stdio.h>
#include <string.h>

char name[10][100];
int i=0;

int menu(){
	int op;
	
	printf("\tRECREATION CLASS\n");
	printf("************************************\n");
	printf("Choose an Operation\n\n");
	printf("[1] Enroll Student\n");
	printf("[2] Print Class List\n");
	printf("[3] Alphabetical Class List\n");
	printf("\n\n");
	
	scanf("%d", &op);
	
	return op;
}
bool class_is_full(){
	if(i<10){
		return 0;
	}
	return 1;
}

void enroll_student(){
	fflush(stdin);
	printf("Enter Name of Student: ");
	gets(name[i]);
	i++;
}

void sort_class_list(){
	int x, y;
	char temp[100];
	
	for(x=0; x<i; x++){
		for(y=0; y<i; y++){
			if(strcmp(name[y],name[y+1])<0){
				strcpy(temp,name[y]);
			    strcpy(name[y],name[y+1]);
			    strcpy(name[y+1],temp);
			}
		}
	}
}

void print_class_list(){
	int x;
	
	printf("List of Students Enrolled in Recreation Class\n\n");
	for(x=i; x>=0; x--){
		puts(name[x]);
	}
}

int main(void){
	
	while(1){
		switch(menu()){
			case 1:
				if(!class_is_full()){
					enroll_student();
				}else{
					printf("Class is full.");
				}
				break;
			case 2:
				print_class_list();
				break;
			case 3:
				sort_class_list();
				print_class_list();
				break;
		}
	}	
}
