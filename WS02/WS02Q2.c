 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>
 
/*Relationship between LCM and GCD
 f(x) × g(x) = LCM [f(x), g(x)] × GCD[f(x), g(x)]*/


int gcd(int a, int b){
	if(a == 0 || b == 0){
		return a + b;
	}
	while(a != b){
		if(a > b){
			a = a - b;
		}else{
			b = b - a;
		}
	}
	return a;
}
int isPrime(int a){
 	if(a == 0 || a == 1){
 		return 0;
	}else{
		int i;
	 	for( i = 2; i <= sqrt(a); i++){
	 		if(a % i == 0){
	 			return 0;
			 }
		 }
		 return 1; 
	 }
 }
void commonPrime(int a, int b){
	int min = a;
	if(min > b){
		min = b;
	}
	printf("All common prime dividers:\t");
	int check, i;
	for( i = 1;i <= min; i++){ 
		check = isPrime(i);
		if(a % i == 0 && b % i == 0 && check == 1){
			printf("%d\t",i);
		}
	}
}
 int main(){
 	int m, n;
 	printf("Enter m, n: ");
 	scanf("%d%d", &m, &n);
 	commonPrime(m,n);
 	printf("\nThe greatest common divider: %d \n",gcd(m,n));
 	printf("The least common multiple: %d ",(m*n)/gcd(m,n));
 	return 0;
 }
