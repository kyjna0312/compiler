#include<stdio.h>
#include<stdlib.h>

int num;
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

	if(token == NUMBER){
		result = num;
		get_token();
	}
	else if(token == LP){
		get_token();
		result = expression();
		if(token == RP) get_token();
		else error(2);
	}
	else error(1);

	return(result);
}

void get_token(){
	char ch;
	ch = getchar();

	if('0'<=ch && ch<='9'){
		token = NUMBER;
	}
	else{
		switch(ch){
			case '+': token = PLUS; break;
			case '*': token = STAR; break;
			case '(': token = LP;   break;
			case ')': token = RP;   break;
			case'\n': token = END;  break;
			default : token = NuLL; break;
		}
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

