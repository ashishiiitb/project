#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}
printlist(struct node *n){
	while(n != NULL){
		printf(" %d",n->data);
		n=n->next;
	}
	printf("\n");

}
void beg_push(struct node** head,int x){
	struct node *n_node=NULL;
	n_node=(struct node*)malloc(sizeof(struct node));
	n_node->data=x;
	n_node->next=*head;
	*head=n_node;

}
void mid_push(struct node* ref,int x){
	struct node *n_node;
	n_node=(struct node*)malloc(sizeof(struct node));
	n_node->data=x;
	n_node->next=ref->next;
	ref->next=n_node;

}

void end_push(struct node* ref,int x){
	struct node* n_node;
	n_node=(struct node*)malloc(sizeof(struct node));
	while(ref->next != NULL){
		ref=ref->next;
	}
	n_node->data=x;
	n_node->next=NULL;
	ref->next=n_node;

}
void pop_n(struct node** rref,int x){
	struct node* ref;
	struct node* prv;
	ref=*rref;
	if(ref != NULL && ref->data == x){
		*rref=ref->next;
		free(ref);
		return;
	}
	while(ref != NULL && ref->data != x ){
		prv=ref;
		ref=ref->next;	
	}
	if(ref == NULL)
		return;
	prv->next=ref->next;
	free(ref);
}
//when we disturb head element then we need double pointer;
void pop_p(struct node **rref,int x){
	struct node *temp,*ref;
	ref=*rref;
	if(x == 0){
		*rref=ref->next;
		free(ref);
		return;	
	}
	
	while(x != 0 && ref != NULL){
		temp=ref;
		ref=ref->next;
		x--;
		
	}
	if(ref == NULL)
		return;
	temp->next=ref->next;
	free(ref);
}

void main(){
	struct node *head=NULL;
	//head=(struct node*)malloc(sizeof(struct node));
	//head->data=1;
	//head->next=NULL;
	beg_push(&head,1);
	beg_push(&head,2);
	beg_push(&head,4);
	mid_push(head->next,3);
	end_push(head,5);
	printlist(head);
	pop_n(&head,2);
	printlist(head);
	pop_p(&head,0);
	printlist(head);
	
}
