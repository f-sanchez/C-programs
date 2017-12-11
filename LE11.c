#include<stdio.h>
#include<stdlib.h>

int acnt[3] = {123, 456, 789};
double bal[3] = {5000, 1000, 3000};
double cash;
int current;

void deposit(int account, double amt){
	int i, flag = 0;
	for(i=0;i<3;i++){
		if(account == acnt[i]){
			flag = 1;
			bal[i] += amt;
			printf("Current Balance: $%.2lf\n", bal[i]);
		}
	}
	if(!flag){
		printf("Account does not exist.\n");
	}
};

void withdrawal(int account, double amt){
	int i, flag = 0;
	for(i=0;i<3;i++){
		if(account == acnt[i]){
			flag = 1;
			bal[i] -= amt;
			printf("Current Balance: $%.2lf\n", bal[i]);
		}
	}
	if(!flag){
		printf("Account does not exist.\n");
	}
};

double checkBalance(int account){
	int i, flag = 0;
	for(i=0;i<3;i++){
		if(account == acnt[i]){
			flag = 1;
			return bal[i];
		}
	}
	if(!flag){
		return 0;
	}
};

int getCoins(double amt){
	return amt/4;
};

void change(int num){
	printf("Quarters: %d\n", num);
};

void selection(int num){
	int account;
	double amt;
	if (num == 1 || num == 2 || num == 3){
		printf("Enter account number: ");
		scanf("%d", &account);
	}
	
	switch(num){
		
		case 0: exit(0);
		
		case 1: printf("Enter amount to deposit: ");
				scanf("%lf", &amt);
				deposit(account, amt);
				break;
				
		case 2: printf("Enter amount to withdraw: ");
				scanf("%lf", &amt);
				withdrawal(account, amt);
				break;
				
		case 3: if (!checkBalance(account)){
					printf("Account does not exist.\n");
				} else {
					printf("Balance: %.2lf\n", checkBalance(account));
				}
				break;		
		
		case 4: printf("Enter amount to change in quarters: ");
				scanf("%lf", &amt);
				change(getCoins(amt));
		
		default: printf("Invalid key.\n");
	}
};

int main(){
	int choice;
	
	while(1){
		printf("Welcome!\n");
		printf("Choose a transaction\n");
		printf("[0] Exit\n");
		printf("[1] Deposit\n");
		printf("[2] Withdraw\n");
		printf("[3] Check Balance\n");
		printf("[4] Get Quarters\n");
		scanf("%d", &choice);
		selection(choice);
	}	
	return 0;
}

