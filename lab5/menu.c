/*
Implement a menu driven program to define a stack of characters. Include push, pop
and display functions. Also include functions for checking error conditionssuch
as underflow and overflow (ref. figure 1) by defining isEmpty and isFull functions.
Use these function in push, pop and display functions appropriately. Use type defined
structure to define a STACK containing a character array and an integer top. Do not
use global variables.
*/


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
int main(){
	int a;
	STACK s;
	char ch;
	int choice;
	initialize_stack(&s);


	
		
	do{
		
				printf("1. push\n");
				printf("2. pop\n");
				printf("3. display\n");
				printf("4. exit\n");
				printf("Enter choice: \n");
				scanf("%d", &choice);
		

		switch(choice){
				

			case 1:
				printf("Enter element to be pushed\n");
				scanf("%d", &a);
				scanf("%c", &ch);
				push(&s, ch);
				printf("Element pushed\n");
				break;

			case 2:
				printf("removing element");
				pop(&s);
				break;
			case 3:
				printf("Displaying elements");
				display(&s);
				break;
			case 4:
				printf("Exiting");
				break;			
			default :
				printf("Invalid operation");	
		}

	}while(choice != 4);
	return 0;
}
