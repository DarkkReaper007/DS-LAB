#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct{
	char stack[MAX];
	int top;
}STACK;
void initialize_stack(STACK *s){
	s->top = -1;
}
int isEmpty(STACK *s){
	return s->top == -1;
}
int isFull(STACK *s){
	return s->top == MAX - 1;
}
char pop(STACK *s){
	if(isEmpty(s)){
		printf("Stack is empty!");
	}else{
		char ch = s->stack[(s->top)--];
		return ch;
	}
}
void push(STACK *s, char ch){
	if(isFull(s)){
		printf("Stack is full!");
	}
	else{
		s->stack[++(s->top)] = ch;
	}
}
void display(STACK *s){
	printf("The stack elements are: ");
	for(int i=s->top; i>=0; i--){
		printf("%c\n", s->stack[i]);
	}
}
void ispalindrome(char string[]){
	
	STACK s;
	initialize_stack(&s);
	int i=0;
	int count =0;
	while(string[i] != '\0'){
		
		push(&s, string[i]);
		i++;
		count++;
	}
	int palin = 0;
	for(int i=0; i<count; i++){
		if(pop(&s) != string[i]){
			
			palin = 1;
			break;

		}
	}
	if(palin == 0){
		printf("Is palindrome");
	}
	if(palin == 1){
		printf("not a palindrome");
	}
	
}
int main(){
	char a[50];
	int n;
	
	printf("Enter the string\n");
	
	scanf("%s", a);
	
	ispalindrome(a);
	return 0;

}