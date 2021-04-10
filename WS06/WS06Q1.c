#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100
void inputArr(double arr[MAX], int *size){
	int i;
	printf("Input size of array n = ");
	scanf("%d",size);
	printf("Enter %d double numbers: ",*size);
	for(i = 0; i < *size;i++){
		scanf("%lf",&arr[i]);
	}
}

void sortArr(double arr[MAX], int size){
	int i, j, temp = 0;
	printf("Before sorting: ");
	for(i = 0; i < size; i++){
		printf("%.1lf\t",arr[i]);
	}
	
	for(i = size - 1; i > 0;i--){
		for(j = 0; j < i;j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printf("\nAfter sorting: ");
	for(i = 0; i < size;i++){
		printf("%.1lf\t",arr[i]);
	}
}
int searchValue(double arr[MAX], int size, double *x){
	int i;
	printf("Enter the value x to be searched: ");
	scanf("%lf",x);
	for(i = 0; i < size; i++){
		if(arr[i] == *x){
			return i;
		}
	}
	return -1;
}
void outputArr(double arr[MAX], int size){
	int i;
	printf("Your array: ");
	for(i = 0; i < size;i++){
		printf(" %.1lf\t",arr[i]);
	}
}
int main(){
	double arr[MAX];
	int size,result;
	double x;
	char choice;
	do{
			printf("\nSelect options:\n");
			printf("1. Enter the list of double numbers\n");
			printf("2. Sort the list in increasing order\n");
			printf("3. Search value x in the list\n");
			printf("4. Display the list\n");
			printf("0. Exit\n");
		do{	
			printf("Your selection (0 -> 4): ");
			fflush(stdin);
			scanf("%c",&choice);
		}while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '0');
		switch (choice) {
			case '1':
				inputArr(arr,&size);
				break;
			case '2':
				sortArr(arr,size);
				break;
			case '3':
				result = searchValue(arr, size, &x);
				if(result == -1){
					printf("Can not found this value in array");
				}else{
					printf("Found %.1lf at position %d",x,result);
				}
				break;	
			case '4':
				outputArr(arr,size);
				break;					
		}
	}while(choice != '0' );
	
	return 0;
}

