#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int reverse(int n){
	int remainder, reverse = 0;
	while(n != 0){
		remainder = n % 10;
		reverse = reverse * 10 + remainder;
		n = n/10;
	}
	return reverse;
}

int main(){
	int m, n, i;
	printf("Enter m: ");
	scanf("%d", &m);
	printf("Enter n: ");
	scanf("%d", &n);
	while(m > n){
		printf("m < n, please reenter!\n");
		printf("Enter m: ");
		scanf("%d", &m);
		printf("Enter n: ");
		scanf("%d", &n);
	}
	printf("All numbers palindromic in the interval [%d;%d] : ",m ,n);
	for(i = m; i <= n;i++){
		if(i ==  reverse(i)){
			printf("%d \t",i);
		}
	}
	return 0;
}
