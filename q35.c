#include<stdio.h>
#include<stdlib.h>
int qnf,qnr;
int qlf,qlr;


struct node{
	struct node *left,*right;
	int key;

};

struct node* newnode(int key){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->key=key;
	temp->left=temp->right=NULL;
	return temp;

}
void popqn(){
	return qnf++;
}
void pushqn(int k){
	if(qnf==qnr)
		qn[qnr]=k;
	else{
		qnr++;
		qn[qnr]=k;	
	}
	
}

struct node* nextright(node *root,int k){
	if(root == NULL)
		return 0;
	
	int qn[n];
	int ql[n];
	int level=0;

	pushqn(root);
	ql.push(level);

}

void test(int *root,int k){
	node *nr=nextright(root,k);
	if(nr !=NULL)
		printf("next right of%d",k,"is%d",nr->key);
	else
		printf("No next right node found for%d",k);

}

void main(){
	struct node *root=newnode(10);	
	root->left=newnode(2);
	root->right=newnode(6);
	root->left->left=newnode(8);
	root->left->right=newnode(4);
	root->right->right=newnode(5);
	printf("%d",root->key);
	test(root,10);

}
