#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

char stack[MAX];
char prefix[MAX];
int top = -1;

void push(char c){
	if(top == MAX - 1){
		printf("Stack Overflow");
	}else{
		stack[++top] = c;
	}
}
char pop(){
	if(top == -1){
		printf("Stack Underflow");
	}else{
		return stack[top--];
	}
}
int eval(char* c){
	char symbol;
	for(int i = strlen(c); i>=0; i--){
		symbol = c[i];

		switch(symbol){
			case '+':
				char op1 = pop();
				char op2 = pop();
				push((op1 - '0') + (op2 - '0'));
				break;
			case '-':
				op1 = pop();
				op2 = pop();
				push((op1 -'0') - (op2 - '0'));
				break;
			case '/':
				op1 = pop();
				op2 = pop();
				push((op1 - '0')/(op2 - '0'));
				break;
			case '*':
				op1 = pop();
				op2 = pop();
				push((op1 - '0') * (op2 - '0'));
				break;
			default:
				push(symbol);			
				

		}

	} return pop();
}
int main(){
	char abcd[50];
	printf("Enter string: ");
	scanf("%s", abcd);
	printf("%d", eval(abcd));
	return 0;

}