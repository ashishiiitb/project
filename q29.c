#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int data;
	struct node *right;

};

struct node* newnode(int data){
	struct node* node;
	node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
void inorder(struct node* root){
	if(root == NULL)
		return ;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
	
}

void postorder(struct node* root){
	if(root == NULL)
		return ;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

void preorder(struct node* root){
	if(root == NULL)
		return ;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

int height(struct node* root){
	if(root==NULL)
		return 0;
	else{
		int lheight=height(root->left);
		int rheight=height(root->right);
		if(lheight > rheight)
			return 1+lheight;
		else
			return 1+rheight;
	}
}
void printlevel(struct node* root,int level){
	if(level == 1)
		printf("%d ",root->data);
	else{
		printlevel(root->left,level-1);
		printlevel(root->right,level-1);
	}
}

void levelorder(struct node* root){
	int h=height(root);
	for(int i=1;i <= h;i++){
		printlevel(root,i);
	}

}


void main(){
	struct node* root=newnode(3);
	root->left=newnode(4);
	root->right=newnode(12);
	root->left->left=newnode(5);
	root->left->right=newnode(15);
	root->right->left=newnode(52);
	root->right->right=newnode(23);
	printf("Preorder traversal\n");
	preorder(root);
	printf("\nInorder traversal\n");
	inorder(root);
	printf("\nPostorder traversal\n");
	postorder(root);
	printf("\nLevelorder traversal\n");
	levelorder(root);
}
