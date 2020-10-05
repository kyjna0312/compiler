#include<stdio.h>
#include<stdlib.h> // can function atoi()

int num;
char str[100];
enum {NuLL, NUMBER, PLUS, STAR, LP, RP, END} token;


int expression();
int term();
int factor();
void get_token();
void error(int i);


void main(){
	int result;
	printf("수식을 입력하십시오 : ");

	get_token();
	result = expression();
	
	if(token != END) error(3);
	else printf("%d\n", result);
}

int expression(){
	int result;
	result = term();

	while(token == PLUS){
		get_token();
		result = result+term();
	}
	
	return(result);
}

int term(){
	int result;
	result = factor();

	while(token == STAR){
		get_token();
		result = result*factor();
	}

	return(result);
}

int factor(){
	int result;

		result = num;
		get_token();
	}
	else if(token == LP){
		get_token();
		result = expression();

		if(token == RP){
			get_token();
		}
		else {
			error(2);
		}
	}
	else {
		error(1);
	}

	return(result);
}

void get_token(){
	char ch = ' ';
	int i = 0;

	do{
		ch = getchar();
		printf("%c\n", ch);

		if('0'<=ch && ch<='9'){
			token = NUMBER;	
			str[i++] = ch; 
		}
		else{
			switch(ch){
				case '+': token = PLUS; printf("plus\n"); break;
				case '*': token = STAR; printf("star\n"); break;
				case '(': token = LP;   printf("LP\n");   break;
				case ')': token = RP;   printf("RP\n");   break;
				case'\n': token = END;  printf("END\n");  break;
				default : token = NuLL; break;
			}
		}
	}while(token == NUMBER);

	if(token == NUMBER)	{
		num = atoi(str);
		printf("%d\n", num);
	}
}

void error(int i){
	switch(i){
		case 1 : printf("error1\n"); break;
		case 2 : printf("error2\n"); break;
		case 3 : printf("error3\n"); break;
	}
	exit(1);
}

