#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* prev;
	struct node* next;
};
void insertf(struct node** head, int data){
	if(*head == NULL){
		struct node* temp = malloc(sizeof(struct node));
		temp->data = data;
		temp->next = NULL;
		temp->prev = NULL;
		*head = temp;
		return;
	}
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;

}
void insertr(struct node** head, int data){
	if(*head == NULL){
		struct node* temp = malloc(sizeof(struct node));
		temp->data = data;
		temp->next = NULL;
		temp->prev = NULL;
		*head = temp;
		return;
	}
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	struct node* temp1 = *head;
	while(temp1->next != NULL){
		temp1 = temp1->next;
	}
	temp->data = data;
	temp->next = NULL;
	temp->prev = temp1;
	temp1->next = temp;
}
int deletefront(struct node** head){
	if(*head == NULL){
		printf("Empty");
		exit(0);
	}
	int data;
	data = (*head)->data;
	(*head) = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
int deleterear(struct node** head){
	if(*head == NULL){
		printf("Empty");
		exit(0);
	}
	int data;
	struct node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	data = temp->data;
	temp->prev->next = NULL;
	temp->next = NULL;
	temp->prev = NULL;
}
void display(struct node* head){
	while(head != NULL){
		printf("%d\t", head->data);
		head = head->next;
	}
}
int main(){
	struct node* head = NULL;
	while(1){
		int choice;
		int data;
		printf("\n1. InsertRear\t 2. Display\t 3. Insertfront\t 4. DeleteRear\t 5.DeleteFront\t 6. Exit\n" );
		printf("Enter choice");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter data: ");
				scanf("%d", &data);
				insertr(&head, data);
				break;
			case 2:
				printf("Displaying elements\n");
				display(head);
				break;
			case 3:
				printf("Enter element");
				scanf("%d", &data);
				insertf(&head, data);
				break;
			case 4:
				printf("deleting");
				deleterear(&head);
				break;
			case 5:
				printf("deleting");
				deletefront(&head);
				break;
			case 6:
				printf("exiting");
				exit(0);	
								

		}
	}
	
	return 0;

}