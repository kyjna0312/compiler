#include<stdio.h>

enum {NuLL, NUMBER, PLUS, STAR, LP, RP, END} token;

void get_char();

void main(){
	printf("input : ");
	get_char();

}

void get_char(){
	char ch;
	do{
		ch = getchar();
	
		if('0'<=ch && ch<='9'){
			token = NUMBER;
			printf("%d\n", token);
		}
		else{
			switch(ch){
				case '+': token = PLUS; printf("%d\n", token); break;
				case '*': token = STAR; printf("%d\n", token); break;
				case '(': token = LP;   printf("%d\n", token); break;
				case ')': token = RP;   printf("%d\n", token); break;
				case '\n': token = END; printf("%d\n", token); break;
				default : token = NuLL; printf("%d\n", token); break;
			}
		}
	}while(token != END);
}


