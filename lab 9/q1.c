#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void enqueue(int data, struct node** head){
	if((*head) == NULL){
		(*head) = malloc(sizeof(struct node));
		(*head)->data = data;
		(*head)->next = NULL;
		return;
	}
	struct node* ptr = *head;
	struct node* temp = malloc(sizeof(struct node));
	while((ptr)->next != NULL){
		ptr = ptr->next;
	}
	temp->data = data;
	temp->next = NULL;
	ptr->next = temp;

}
int dequeue(struct node** head){
	if((*head) == NULL){
		printf("Queue is empty");
		exit(0);
	}
	int a;
	a = (*head)->data;
	(*head) = (*head)->next;
	return a;
}
void display(struct node* head){
	while(head != NULL){
		printf("%d\t",(head)->data);
		head = head->next;
	}
}
int main(){
	struct node* head = NULL;
	enqueue(45, &head);
	enqueue(55, &head);
	display(head);
	printf("\n");
	dequeue(&head);
	display(head);
	return 0;
}