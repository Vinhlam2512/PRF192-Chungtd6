#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int reverse(int n){
	int remainder, reverse = 0;
	while(n != 0){
		remainder = n % 10;
		reverse = reverse * 10 + remainder;
		n = n/10;
	}
	return reverse;
}

int sum(int n){
	int remainder, sum = 0;
	while(n != 0){
		remainder = n % 10;
		sum = sum  + remainder;
		n = n/10;
	}
	return sum;
}

void binaryNumber(int n){
	int i, count = 0 , a[10];
	printf("%d in binary number format is: ",n);
	for(i = 0; n > 0; i++){
		a[i] = n % 2;
		n = n / 2;
		count++;
	}
	for(i = count-1; i >= 0;i--){
		printf("%d" ,a[i]);
	}
	printf("\n");
	
}


int main(){
	int n;
	printf("Enter n = ");
	scanf("%d",&n);
	binaryNumber(n);
	printf("\nEnter n = ");
	scanf("%d",&n);
	printf("The sum of all digits in %d is %d ",n, sum(n));
	printf("\nThe reverse number of %d is %d ",n, reverse(n));
	return 0;
}
