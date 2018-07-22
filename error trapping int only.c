#include <stdio.h>
//#include <ctype.h>


int main() {
	int a;
	
	while(scanf("%d", &a)==0) //if scanf failed to scan an integer; yields false
	{
	    printf("Invalid input. Try again\n");
	    fflush(stdin);
	}
	return(0);
}


/*******from source*****************
#include <stdio.h>
//#include <ctype.h>

int main () {
int a;
    
   while(scanf("%d", &a)==0) //if scanf failed to scan an integer; yields false
	{
	    printf("Invalid input. Try again\n");
	    int c;
	    fflush(stdin);
	   // while((c=getchar())!='\n' && c!=EOF); //clear the stdin
	}
   return(0);
}
************************************/
