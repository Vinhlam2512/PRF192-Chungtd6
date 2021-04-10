#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define max 1000

void inputString(char s[]){
	printf("Input a string: ");
	fflush(stdin); // remove buffer data
	gets(s);
}

int countWord(char s[]){
	int len = strlen(s);
	int i, count = 1;
	for(i = 0; i < len - 1; i++){
		if(s[i] == ' ' && s[i+1] != ' ' ){ // check space between 2 word
			count++;
		}
	}
	return count;
}

void splitString(char s[]){
	int count  = countWord(s);
	char x[1000];
	strcpy(x, s);
	printf("The original string: ");
	puts(x);
	char *token = strtok(x," "); // token == each word in string
	printf("\nNumber of words in the string: %d, they are\n",count);
	while (token != NULL){
		printf("%s\n",token);
		token = strtok(NULL, " ");
	}
}

void convertProper( char s[]){
	printf("The original string: ");
	puts(s);
	int i;
	int len = strlen(s);
	for(i = 0; i < len; i++){
		if(s[i] == ' ' && s[i+1] != ' ' ){ // check space between 2 word
			if(s[i+1] >= 91 && s[i+1] <= 122){
				s[i+1]= s[i+1] -32;// convert upper
			}
		}
		if(s[0] >= 91 && s[0] <= 122){
				s[0] = s[0] - 32; // convert upper
		}
	}
	printf("The proper form: ");
	puts(s);
}

void removeRedundant(char s[]){
	char x[1000];
	strcpy(x,s);
	int len = strlen(x);
	int i, j;
	printf("The original string: ");
	puts(s);
	for(i = 0; i < len; i++){
		if(x[i] == x[i+1] && x[i] == ' '){
			strcpy(&x[i],&x[i+1]);
			i--;
//			x[len]=' ';
		}
	}
	if(x[0]==32){
		strcpy(&x[0],&x[1]);
//		x[len] = NULL;
	}
//	if(x[len]==32){
//		x[len] = NULL;
//	}
	printf("The cleaned form:");
	puts(x);
}

void checkName(char s[]){
	int len = strlen(s);
	int check = 0;
	int i;
	for(i = 0; i < len;i++){
		if(isalpha(s[i]) == 0 && s[i] != ' '){ // function isalpha return 0 if s[i] is not word and return another if is word
			check++;
			break;
		}
	}
	if(check != 0){
		printf("The string: %s is not a valid name",s);
	}
	if(check == 0){
		printf("The string: %s is a valid name",s);
	}
}
int main(){
	char choice;
	char s[max];
	do{
		printf("\nChoose one of the following options: ");
		printf("\n1. Input a string");
		printf("\n2. Split a string into words");
		printf("\n3. Convert a string into proper form");
		printf("\n4. Remove redundant spaces");
		printf("\n5. Check valid name");
		printf("\n0. Exit\n");
		do{
			printf("Your selection (0 -> 5): ");
			fflush(stdin);
			scanf("%c",&choice);
		}while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '0');
		switch(choice) {
			case '1':
				inputString(s);
				break;
			case '2':
				splitString(s);
				break;
			case '3':
				convertProper(s);
				break;
			case '4':
				removeRedundant(s);
				break;
			case '5':
				checkName(s);
				break;			
		}
	}while(choice != '0');
	return 0;
}

