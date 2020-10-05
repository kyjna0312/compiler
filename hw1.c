#include<stdio.h>
#include<stdlib.h> // can function atoi()
#include<ctype.h> // can function isdigit()

int num;
char str[100];
enum {NuLL, NUMBER, PLUS, STAR, LP, RP, END} token;


int expression();
int term();
int factor();
int get_token();
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

int get_token(){
	char ch =' ';
	int i = 0;

	while(ch == ' ' || ch == '\t'){
		ch = getchar();
	}

	if(isdigit(ch)){
		do{
			str[i++] = ch;
			ch = getchar();
		}while(isdigit(ch));
	}
	else if(ch == '\n'){
		return END;
	}
	else if(ch == '+'){
		ch = getchar();
		return PLUS;
	}
	else if(ch == '*'){
		ch = getchar();
		return STAR;
	}
	else if(ch == '('){
		ch = getchar();
		return LP;
	}
	else if(ch == ')'){
		ch = getchar();
		return RP;
	}
	num = atoi(str);
	printf("%d\n", num);
	return NUMBER;
}

void error(int i){
	switch(i){
		case 1 : printf("error1\n"); break;
		case 2 : printf("error2\n"); break;
		case 3 : printf("error3\n"); break;
	}
	exit(1);
}

