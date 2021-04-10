#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void FunctionToss(){
	int number, tosses;
	printf("Enter number of tosses: ");
	scanf("%d",&number);
	srand(time(NULL));
	tosses =1 + rand() % number;
	printf("Number of heads: %d", tosses);
	printf("\nNumber of tails: %d", number-tosses);
	double percent=(double)tosses/number*100;
	printf("\nPercentage of heads for all tosses: %.2f", percent);
}

int main(){
	int check;
	do{
		printf("Select options:\n1. Start tossing\n0. Exit\n");
		printf("Your selection (0 -> 1): ");
		scanf("%d",&check);
	}while(check== 1);
	if(check==1) {
		FunctionToss();
	}else if(check==0) {
		printf("Exit!");
	}else{
		printf("1");
	}

	return 0;
}
