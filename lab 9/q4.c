#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* del(struct node* head){
	struct node* ptr = head;
	while(ptr->next != NULL){
		if(ptr->data == ptr->next->data){
			ptr->next = ptr->next->next->next;
		}
		ptr = ptr->next;
	}
	return head;
}
void display(struct node* head){
	while(head != NULL){
		printf("%d\t", head->data);
		head = head->next;
	}
}
int main(){
	printf("df");
	struct node* head = malloc(sizeof(struct node));
	head->data = 1;
	struct node* head1 = malloc(sizeof(struct node));
	head1->data = 2;
	head->next = head1;
	struct node* head2 = malloc(sizeof(struct node));
	head2->data = 2;
	head1->next = head2;
	head2->next = NULL;
	struct node* idk = del(head);
	display(idk);
	return 0;
}