#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int selection(){
	int choice;
	printf("Choose a transaction\n");
	printf("[1] Deposit\n");
	printf("[1] Withdraw\n");
	printf("[1] Check Balance\n");
	printf("[1] Get Quarters\n");
	
	scanf("%d", &choice);
}

int deposit(){
	int currentBal = 0, depositAmount = 0;
	
	printf("Enter amount to deposit: ");
	scanf("%d", &depositAmount);
	return currentBal + depositAmount;
}

main(){
	int currentBal = 0, depositAmount = 0;
	
	while(1){
		
	//	printf("WELCOME!\n);
			
		switch(selection()){
			case 0: exit(0);
			case 1: 
					printf("%d", deposit());
					break;
					
		}
	}
}


