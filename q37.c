#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
};
int max(int a,int b){
	return a>b?a:b;
}

struct node* newnode(int key){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->right=NULL;
	temp->left=NULL;
	temp->height=1;
	return temp;

}
int height(struct node *node){
	if(node==NULL)
		return 0;
	else
		return node->height;
}

int balance(struct node* root){
	if(root==NULL)
		return 0;
	else
		return (height(root->left)-height(root->right));
}

struct node* left_rotate(struct node *node){
	struct node* temp=node->right;
	struct node* temp1=temp->left;
	temp->left=node;
	node->right=temp1;
	
	node->height=1+max(height(node->left),height(node->right));
	temp->height=1+max(height(temp->left),height(temp->right));
	
	return temp;
}

struct node* right_rotate(struct node *node){
	struct node* x=node->left;
	struct node* y=x->right;
	x->right=node;
	node->left=y;

	node->height=1+max(height(node->left),height(node->right));
	x->height=1+max(height(x->left),height(x->right));
	
	return x;
}

struct node* insert(struct node *root,int key){
	if(root==NULL)
		return newnode(key);
	if(key < root->data)
		root->left=insert(root->left,key);
	else if(key > root->data)
		root->right=insert(root->right,key);
	else
		return root;
	root->height=1+max(height(root->left),height(root->right));

	int h=balance(root);
	if(h<-1 && key > root->right->data)	//RR
		return left_rotate(root);

	if(h>1 && key < root->left->data)	//LL
		return right_rotate(root);

	if(h>1 && root->left->data < key){	//LR
		root->left=left_rotate(root->left);
		return right_rotate(root);
	}

	if(h<-1 && root->right->data > key){	//RL
		root->right=right_rotate(root->right);
		return left_rotate(root);
	}

	return root;
}

void printpreorder(struct node *root){
	if(root!=NULL){
	printf("%d ",root->data);
	printpreorder(root->left);
	
	printpreorder(root->right);
	}
}

struct node* search(struct node* root,int key){
	
	if(root == NULL || root->data == key)
		return root;
	if(root->data < key)
		search(root->right,key);
	else
		search(root->left,key);
	
		//printf("NOT EXIST");
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    // loop down to find the leftmost leaf 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

struct node* delete(struct node* root,int key){
	if(root == NULL)
		return root;
	if(key<root->data)
		root->left=delete(root->left,key);
	else if(key>root->data)
		root->right=delete(root->right,key);
	else{
		if(root->left == NULL){
			struct node *temp=root->right;
			free(root);
			return temp;			
		}
		else if (root->right == NULL){
        
            		struct node *temp = root->left;
          		free(root);
            		return temp;
        	}else{
			struct node* temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = delete(root->right, temp->data);
		}
	}
	if(root == NULL)
		return root;
	root->height=1+max(height(root->left),height(root->right));

	int h=balance(root);
	if(h<-1 && key > root->right->data)	//RR
		return left_rotate(root);

	if(h>1 && key < root->left->data)	//LL
		return right_rotate(root);

	if(h>1 && root->left->data < key){	//LR
		root->left=left_rotate(root->left);
		return right_rotate(root);
	}

	if(h<-1 && root->right->data > key){	//RL
		root->right=right_rotate(root->right);
		return left_rotate(root);
	}

	return root;

}

void main(){
	struct node *root=NULL;
	root=insert(root,50);
	root=insert(root,30);
	root=insert(root,20);
	root=insert(root,10);
	//root=insert(root,10);
	root=insert(root,70);
	root=insert(root,80);
	root=insert(root,25);
	root=insert(root,65);
	printf("Element of tree:");
	printpreorder(root);
	struct node *temp=search(root,30);
	if(temp!=NULL)
		printf("\n There exist in the tree:%d",temp->data);
	else
		printf("\n not found in the tree");
	delete(root,30);
	printf("\nElement of tree:");
	printpreorder(root);

}
