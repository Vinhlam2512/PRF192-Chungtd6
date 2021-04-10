#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void input(int *num, int *den); 
void display(int num, int den); 
void simplify(int *num, int *den); 


int main(){
	int a, b;
	char c;
	do{
		input(&a,&b);
		display(a,b);
		simplify(&a,&b);
		printf("\nAnother run (y/n)? ");
		fflush(stdin);
		scanf("%c",&c);
	}while(c == 'y');
	return 0;
}


void input(int *num, int *den){
	int numerator,denominator;
	printf("\n1. Input fraction\n");
	printf("\nEnter numerator: ");
	scanf("%d",num);
	getInt(*num);
	printf("Enter denominator: ");
	scanf("%d",den);
	while(*den == 0){
		printf("Enter denominator: ");
		scanf("%d",den);
	}
	
}

void display(int num, int den){
	printf("%d/%d = ",num,den);
}
void simplify(int *num, int *den){
	int a = *num, b = *den;
	*num = *num/gcd(a,b);
	*den = *den/gcd(a,b);
	if(*den < 0){
		printf("-%d/%d",*num,-*den);
	}else{
		printf("%d/%d",*num,*den);
	}
}
int gcd(int x, int y){
	if(x == 0 || y == 0){
		return x + y;
	}
	while(abs(x) != abs(y)){
		if(abs(x) > abs(y)){
			x = abs(x) - abs(y);
		}else{
			y = abs(y) - abs(x);
		}
	}
	return abs(x);
}

