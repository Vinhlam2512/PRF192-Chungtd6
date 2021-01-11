#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
	double a, b, c, x;
	printf("Enter a = ");
	scanf("%lf", &a);
	printf("Enter b = ");
	scanf("%lf", &b);
	printf("Enter c = ");
	scanf("%lf", &c);
	printf("Enter x = ");
	scanf("%lf", &x);
	double s1 = a*x*x + b*x + c;
	double s2 = sqrt(b*b - 4*a*c);
	printf("\nS1 = %0.2lf,\t", s1);
		if( b*b - 4*a*c > 0){
		printf("S2 = %0.2lf", s2);
	} else {
		printf("S2 = 0");
	}
	printf("\n\nEnter a, b, c = ");
	scanf("%lf %lf %lf", &a, &b, &c);
	double p = (a + b + c) / 2;
	double area = sqrt(p*(p - a)*(p - b)*(p - c));
	if( a + b > c && b + c > a && a + c > b){
		printf("\nPerimeter = %0.3lf", p*2);
		printf("\nArea = %0.3lf", area);
	}else{
		printf("a, b, c are not sides of a triangle.");
	}
	return 0;
}
