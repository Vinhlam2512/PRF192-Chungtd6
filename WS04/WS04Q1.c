#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void input(int *num, int *den); 
void display(int num, int den); 
void simplify(int *num, int *den); 


int main(){
	int a, b;
	input(&a,&b);
	display(a,b);
	return 0;
}


void input(int *num, int *den){
	printf("1. Input fraction\n");
	printf("\nEnter numerator: ");
	scanf("%d",&num);
	printf("Enter denominator: ");
	scanf("%d",&den);
	while(den == 0){
		printf("Enter denominator: ");
		scanf("%d",&den);
	}
	
}

void display(int num, int den){
	printf("2. Simplify fraction\n");
	printf("%d/%d", num, den);
}
