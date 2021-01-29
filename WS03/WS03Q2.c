#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	double a, b, c, delta, x1, x2;
	printf("Enter a: ");
	scanf("%lf",&a);
	printf("Enter b: ");
	scanf("%lf",&b);
	printf("Enter c: ");
	scanf("%lf",&c);
	delta = b*b - 4*a*c;
	if(a == 0){
		if(b == 0 && c != 0){
			printf("The equation has no solution");
		}else if(b == 0 && c == 0){
			printf("Equations have solutions for all x");
		}else{
			x1 = -c / b;
			printf("Equations have a unique solution : x = %0.2lf",x1);
		}
	}
	if( a != 0){
		if(delta > 0){
			x1 = (-b + sqrt(delta))/(2*a);
			x2 = (-b - sqrt(delta))/(2*a);
			printf("The equation has two specific differences : x1 = %0.2lf\t x2 = %0.2lf ",x1 ,x2);
		}
		if(delta == 0){
			x1 = x2 = -b/(2*a);
			printf("Equations have double solutions: x1 = x2 = %0.2lf",x1);
		}
		if(delta < 0){
			printf("The equation has no solution");
		}
	}
	return 0;
}
