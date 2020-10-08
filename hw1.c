#include<stdio.h>
#include<stdlib.h> // can function atoi()
#include<ctype.h> // can function isdigit()

int num;
enum { NuLL, NUMBER, PLUS, STAR, LP, RP, END } token;


int expression();
int term();
int factor();
int get_token();
void error(int i);


void main() {
	int result;
	printf("수식을 입력하십시오 : ");

	get_token();
	result = expression();

	if (token != END) error(3);
	else printf("%d\n", result);
}

int expression() {
	int result;
	result = term();

	while (token == PLUS) {
		get_token();
		result = result + term();
	}

	return(result);
}

int term() {
	int result;
	result = factor();

	while (token == STAR) {
		get_token();
		result = result * factor();
	}

	return(result);
}

int factor() {
	int result;

	if (token == NUMBER) {
		result = num;
		get_token();
	}
	else if (token == LP) {
		get_token();
		result = expression();

		if (token == RP) {
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

int get_token() {
	char ch = ' ';
	char str[100] = { 0 };
	int i = 0;

	while (ch == ' ' || ch == '\t') {
		ch = getchar();
	}

	if (isdigit(ch)) {
		do {
			str[i++] = ch;
			ch = getchar();
		} while (isdigit(ch));
	}
	else if (ch == '\n') {
		return token = 6;
	}
	else if (ch == '+') {
		ch = getchar();
		return token = 2;
	}
	else if (ch == '*') {
		ch = getchar();
		return token = 3;
	}
	else if (ch == '(') {
		ch = getchar();
		return token = 4;
	}
	else if (ch == ')') {
		ch = getchar();
		return token = 5;
	}

	num = atoi(str);
	return token = 1;
}

void error(int i) {
	switch (i) {
	case 1: printf("error1\n"); break;
	case 2: printf("error2\n"); break;
	case 3: printf("error3\n"); break;
	}
	exit(1);
}
