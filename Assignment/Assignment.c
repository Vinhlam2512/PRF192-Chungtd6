#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct books{
	char title[100];
	char code[100];
	int quantity;
	double price;
}mark[50],temp[50];

void saveAsFile(int amount){
	FILE *fp;
	fp = fopen("ListBook.txt", "w");
	fprintf(fp, "Number of books %d\n", amount);
	fprintf(fp, "\n\n%-30s %-24s %-18s %-12s %-6s ","Code","Title","Quantity","Price","Value");
	int i;
	for(i = 1; i <= amount; i++){
		fprintf(fp,"%-30s %-24s %-18d %-12.1lf %-6.1lf ",mark[i].code, mark[i].title, mark[i].quantity, mark[i].price, mark[i].quantity * mark[i].price);
	}
	fclose(fp);
}

void listOfBook(char code[], char title[], int quantity, double price, int amount){
	int i = 1;
	int j;
	while( i <= amount){
		printf("\nBook %d :",i);
		printf("\nEnter code: ");
//		fflush(stdin);
		scanf("%s",&mark[i].code);
		
		printf("Enter title: ");
//		fflush(stdin);
		scanf("%s",&mark[i].title);

		do{
			printf("Enter quantity: ");
			scanf("%d", &mark[i].quantity);
			if(mark[i].quantity < 0){
				printf("Invalid, please reenter\n");
			}
		}while(mark[i].quantity < 0);
		do{
			printf("Enter price: ");
			scanf("%lf", &mark[i].price);
			if(mark[i].price < 0){
			printf("Invalid, please reenter\n");
			}
		}while(mark[i].price < 0);
		i++;
		
	}
}

void displayList(char code[], char title[], int *quantity, double *price, int *amount){
	int i = 1;
	double value;
	double total;
	printf("\n%-30s %-24s %-18s %-12s %-6s ","Code","Title","Quantity","Price","Value");
	for(i = 1; i <= *amount; i++){
		printf("\n%-30s %-24s %-18d %-12.1lf %-6.1lf ",mark[i].code, mark[i].title, mark[i].quantity, mark[i].price, mark[i].quantity * mark[i].price);
		total = total + mark[i].quantity * mark[i].price;
	}
	printf("\n                                                                            Total value: %.1lf",total);

}

void sortList( int amount){
	int i, j;
//	char temp[100];
	for(i = 1; i <= amount;i++){
		for(j = i; j <= amount;j++){
			if(strcmp(mark[i].code,mark[j].code) > 0){
				struct books temp = mark[j];
				mark[j] = mark[i];
				mark[i] = temp;
			}
		}
	}
}

void loadData(int amount){
	char check;
	do{
		
		printf("DO YOU WANT TO SAVE LIST AS FILE (Y/N):");
		fflush(stdin);
		scanf("%c",&check);
		if(check == 'y' || check == 'n'){
			check = check - 32;
		}
		}while(check != 'Y' && check != 'N' );
		if(check == 'Y'){
			saveAsFile(amount);
			printf("The file ListBook.txt has been loaded");
		}
}

void findMaxPrice(int amount){
	double max;
	int i;
	for(i = 1; i <= amount; i++){
		if(max < mark[i].price){
			max = mark[i].price;
		}
	}
	printf("The max price in the list of book is %.1lf",max);
	printf("\n%-30s %-24s %-18s %-12s %-6s ","Code","Title","Quantity","Price","Value");
	for(i = 1; i <= amount;i++){
		if(mark[i].price == max){
			printf("\n%-30s %-24s %-18d %-12.1lf %-6.1lf ",mark[i].code, mark[i].title, mark[i].quantity, mark[i].price, mark[i].quantity * mark[i].price);
		}
	}
}

void findAndEdit(int amount){
	char code[50];
	printf("Enter code you want to find and edit : ");
	fflush(stdin);
	scanf("%s",&code);
	int check;
	int i;
	for(i = 1; i <= amount;i++){
		if(strcmp(code,mark[i].code) == 0){
			check = 1;
			break;
		}else{
			check = 0;
		}
	}
	if(check == 0){
		printf("Dont have this code in the list book, please try again!");
	}
	if(check == 1){
		printf("Edit book which have code %s",code);
		printf("\nEnter title: ");
		scanf("%s",&mark[i].title);

		do{
			printf("Enter quantity: ");
			scanf("%d", &mark[i].quantity);
			if(mark[i].quantity < 0){
				printf("Invalid, please reenter\n");
			}
		}while(mark[i].quantity < 0);
		do{
			printf("Enter price: ");
			scanf("%lf", &mark[i].price);
			if(mark[i].price < 0){
				printf("Invalid, please reenter\n");
			}
		}while(mark[i].price < 0);
		do{
			printf("DO YOU WANT TO UPDATE NEW LIST (Y/N):");
			fflush(stdin);
			scanf("%c",&check);
			if(check == 'y' || check == 'n'){
					check = check - 32;
			}
		}while(check != 'Y' && check != 'N' );
		if(check == 'Y'){
					saveAsFile(amount);
		}
	}
}

void findAndDelete(int *amount){
	char dlcode[5];
	printf("\nEnter the code of the book which you want to delete: ");
	fflush(stdin);
	scanf("%s", dlcode);
	int i, check = 0;
	for(i = 1; i <= *amount; i++){
		if(strcmp(dlcode, mark[i].code) == 0){
			check = 1;
			break;
		}
	}
	if(check == 0) printf("The code %s is not exist!\n", dlcode);
	else{
		int j;
		for(i = 1; i <= *amount; i++){
			mark[j] = mark[j+1];
		}
		*amount--;
		printf("The book which has code %s has been deleted!\n", dlcode);
		char check;
		do{
			printf("\nDo you want to update the file ListBook.txt (y/n)? ");
			fflush(stdin);
			scanf("%c", &check);
			if(check < 'a') check -= ('a' - 'A'); 
		}while(check != 'y' && check != 'n');
		if(check == 'y') saveAsFile(*amount);
	}	
}
int main(){
	
	int count = 0;
	int amount;
	char choice;
	char title[100], code[100];
	int quantity;
	double price;
	do{
		
		printf("\nSelect options:");
		printf("\n1. Enter the list of books");
		printf("\n2. Display the list of books");
		printf("\n3. Sort the list of books by code");
		printf("\n4. Load data from file");
		printf("\n5. Find the (first) max price");
		printf("\n6. Find by code and edit the book");
		printf("\n7. Find by code and delete the book");
		printf("\n0. Exit");
		do{
			printf("\nYour selection (0 -> 7): ");
			fflush(stdin);
			scanf("%c",&choice);
			if(choice != '1'&&choice != '2'&&choice != '3'&&choice != '4'&&choice != '5'&&choice != '6'&&choice != '7'){
				printf("You need to choose 0 to 7");
			}
		}while(choice != '1'&&choice != '2'&&choice != '3'&&choice != '4'&&choice != '5'&&choice != '6'&&choice != '7'&&choice != '0');
		switch(choice){
			case '1':
				count = count + 1;
				printf("Enter number of books: ");
				scanf("%d",&amount);
				listOfBook(code,title,quantity,price,amount);
				char check;
				break;
			case '2':
				if(count == 0){
					printf("Don't have data to show list, you must be select 1 first");
				}else{
					displayList(code,title,&quantity,&price,&amount);
				}
				
				break;
			case '3':
				if(count == 0){
					printf("Don't have data to sort, you must be select 1 first");
				}else{
					sortList(amount);
					displayList(code,title,&quantity,&price,&amount);
				}
				
				break;	
			case '4':
				if(count == 0){
					printf("Don't have data to load, you must be select 1 first");
				}else{
					loadData(amount);
					displayList(code,title,&quantity,&price,&amount);
				}
				
				break;
			case '5':
				if(count == 0){
					printf("Don't have data to find max price, you must be select 1 first");
				}else{
					findMaxPrice(amount);
				}
				break;
			case '6':
				if(count == 0){
					printf("Don't have data to show list, you must be select 1 first");
				}else{
					findAndEdit(amount);
					displayList(code,title,&quantity,&price,&amount);
				}
				break;
			case '7':
				if(count == 0){
					printf("Don't have data to show list, you must be select 1 first");
				}else{
					displayList(code,title,&quantity,&price,&amount);
					findAndDelete(&amount);
				}
				break;		
					
		}
	}while(choice != '0');
	return 0;
}

