#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double min(double a, double b, double c){
	int min = a;
	if(b < min){
		min = b;
	}
	if(c < min){
		min = c;
	}
	return min;
}

double max(double a, double b, double c){
	int max = a;
	if(max < b){
		max = b;
	}
	if(max  < c){
		max = c;
	}
	return max;
}

void sort(double a, double b, double c){
	double temp = 0;
	if(a > b){
		temp = b;
		b = a;
		a = temp;
	}
	if(a > c){
		temp = c;
		c = a;
		a = temp;
	}
	if(b > c){
		temp = c;
		c = b;
		b = temp; 
	}
	printf("\nArrange them in ascending order : %0.2lf %0.2lf %0.2lf", a, b, c);
}

int main(){
	double a, b, c;
	printf("Enter a, b, c :");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("\nMinimum values among them: %0.2lf", min(a,b,c));
	printf("\nMax values among them: %0.2lf", max(a,b,c));
	sort(a, b, c);
}
