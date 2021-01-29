 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>

int main(){
	int n;
	int i;
	printf("Enter n = ");
	scanf("%d",&n);
	while(n <= 5){
		printf("\nn must be > 5, please reenter!"); // reinput when  n <= 5
		printf("\nEnter n = ");
		scanf("%d",&n);
	}
	int S1 = 0, S2 = 1;
	double S3 = 0;
	for( i = 1; i <= n; i++){
		
		S1 = S1 + i;
	}
	printf("S1 = %d",S1);
	for( i = 1; i <= n; i++){
		S2 = S2*i;
	}
	printf("\nS2 = %d", S2);
	for( i = 1; i <= n;i++){
		S3 = S3 + 1/(double)i;
	}
	printf("\nS3 = %0.4lf",S3);
	
	printf("\n\nEnter n = ");
	scanf("%d",&n);
	int count = 0;
	for( i = 1; i <= n ;i++){
		if(n % i == 0){
			count++;
		}
	}
	if(count == 2){
			printf("%d is a prime number", n);
	}else{
			printf("%d is not a prime number", n);
	}
	
	return 0;
}
