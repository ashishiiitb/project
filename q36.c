#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newnode(int key){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->right=NULL;
	temp->left=NULL;
	return temp;

}

struct node* insert(struct node *root,int key){
	if(root==NULL)
		return newnode(key);
	if(key<root->data)
		root->left=insert(root->left,key);
	else
		root->right=insert(root->right,key);

}

void printinorder(struct node *root){
	if(root!=NULL){
	printinorder(root->left);
	printf("%d ",root->data);
	printinorder(root->right);
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
 
    /* loop down to find the leftmost leaf */
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
        	}
		struct node* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = delete(root->right, temp->data);

	}
		
	return root;

}

void main(){
	struct node *root=NULL;
	root=insert(root,50);
	insert(root,30);
	insert(root,60);
	insert(root,70);
	insert(root,10);
	//insert(root,70);
	insert(root,40);
	insert(root,45);
	insert(root,65);
	printf("Element of tree:");
	printinorder(root);
	struct node *temp=search(root,30);
	if(temp!=NULL)
		printf("\nThere exist in the tree:%d",temp->data);
	else
		printf("\nnot found in the tree");
	delete(root,50);
	printf("\nElement of tree:");
	printinorder(root);

}
