#include<stdio.h>

int num;
enum {NULL, NUMBER, PLUS, STAR, LP, RP, END} token;

void main(){
	int result;
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
	
	return(resulr);
}

int term(){
	int result;
	result = factor();

	while(token == STAR){
		get_token();
		result = result*factor()
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

}

void error(int i){
	switch(i){
		case 1 : print("error1\n"); break;
		case 2 : print("error2\n"); break;
		case 3 : print("error3\n"); break;
	}
	exit(1);
}

