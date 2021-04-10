#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int MaxMin(int k, int *max, int *min) {
	int n;
	k=0;
	while(1){
		printf("Nhap vao so nguyen duong: ");
		scanf("%d", &n);
		if(n==0) {
			break;
		}	
		if(n>0) k++;
		if(*max<n) *max=n; 
		if(*min>n) *min=n; 
	}
	
		
	
	return k;
		
}

int main() {
	int k, min, max;
	k=MaxMin(k, &max, &min);
	printf("So so nguyen duong duoc nhap vao la: %d\n", k);
	if(max<k) printf("Max va Min < so so nguyen duong.");
	else {
		printf("Max= %d\n", max);
		printf("Min= %d", min);
	}	
	
	
}
