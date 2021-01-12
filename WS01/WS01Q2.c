#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	double min = a, max = c;
	if(min > b){
		min = b;
		if(c < min){
			printf("\nMin = %lf", c);
		}else{
			printf("\nMin = %lf", b);
		}
	}else if(min > c){
		min = c;
		if( b < min){
			printf("\nMin = %lf", b);
		}else{
			printf("\nMin = %lf", c);
		}
	}else{
		printf("\nMin = %lf", a);
	}
	if(max < b){
		max = b;
		if(max < a){
			printf("\nMax = %lf", a);
		}else{
			printf("\nMax = %lf", b);
		}
	}else if(max < a){
		max = a;
		if(max < b){
			printf("\nMax = %lf", b);
		}else{
			printf("\nMax = %lf", a);
		}
	}else{
		printf("\nMax = %lf", c);
	}
	
}
