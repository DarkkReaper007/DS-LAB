#include<stdio.h>
#include<stdlib.h>
#define MAX 32

typedef struct{
	int stack[MAX];
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
int pop(STACK *s){
	if(isEmpty(s)){
		printf("Stack is empty!");
	}else{
		int ch = s->stack[(s->top)--];
		return ch;
	}
}
void push(STACK *s, int ch){
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
		printf("%d\n", s->stack[i]);
	}
}
void decimal_to_binary(int decimal){
	STACK s;
	int c=0;
	initialize_stack(&s);

	while(decimal > 0){
		int rem = decimal % 2;
		push(&s, rem);
		decimal /= 2;
		c++;
	}
	printf("Binary equivalent: ");
	for(int i=0 ; i<c; i++){
		printf("%d", pop(&s));
	}

}
int main(){
	int decimal;
	printf("Enter decimal value: ");
	scanf("%d", &decimal);
	decimal_to_binary(decimal);
	return 0;
}