#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 999999;

struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
	int count;
	int sum;
	int min;
	int max;
	int mingap;
};
int max(int a,int b){
	return a>b?a:b;
}

int min2(int a,int b){
	return a<b?a:b;
}

struct node* newnode(int key){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->right=NULL;
	temp->left=NULL;
	temp->height=1;
	temp->count=1;
	temp->sum=key;
	temp->min=key;
	temp->max=key;
	temp->mingap=99999;
	return temp;

}
int height(struct node *node){
	if(node==NULL)
		return 0;
	else
		return node->height;
}

int count(struct node *node){
	if(node==NULL)
		return 0;
	else
		return node->count;
}

int presum(struct node *node){
	if(node==NULL)
		return 0;
	else
		return node->sum;
}

int minimum(struct node *node){
	if(node==NULL)
		return 99999;
	else
		return node->min;
}

int maximum(struct node *node){
	if(node==NULL)
		return 0;
	else
		return node->max;
}

int mingap(struct node *node){
	if(node==NULL)
		return 99999;
	else
		return node->mingap;
}

int min(int a,int b,int c){
	if(a<b){
		if(a<c)
			return a;
		else
			return c;	
	}else
		if(b<c)
			return b;
		else
			return c;
}

int maxi(int a,int b,int c){
	if(a>b){
		if(a>c)
			return a;
		else
			return c;	
	}else
		if(b>c)
			return b;
		else
			return c;
}

int balance(struct node* root){
	if(root==NULL)
		return 0;
	else
		return (height(root->left)-height(root->right));
}

int mini(int a,int b,int c,int d){
	if(a < b)
		return min(a,c,d);
	else
		return min(b,c,d);
}

struct node* left_rotate(struct node *node){
	struct node* temp=node->right;
	struct node* temp1=temp->left;
	temp->left=node;
	node->right=temp1;
	
	node->height=1+max(height(node->left),height(node->right));
	temp->height=1+max(height(temp->left),height(temp->right));

	node->count=1+count(node->left)+count(node->right);
	temp->count=1+count(temp->left)+count(temp->right);

	node->sum=node->data+presum(node->left)+presum(node->right);
	temp->sum=temp->data+presum(temp->left)+presum(temp->right);

	node->min=min(node->data,minimum(node->left),minimum(node->right));
	temp->min=min(temp->data,minimum(temp->left),minimum(temp->right));	
	
	node->max=maxi(node->data,maximum(node->left),maximum(node->right));
	temp->max=maxi(temp->data,maximum(temp->left),maximum(temp->right));

	node->mingap=mini(mingap(node->left),mingap(node->right),node->data-maximum(node->left),minimum(node->right)-node->data);
	temp->mingap=mini(mingap(temp->left),mingap(temp->right),temp->data-maximum(temp->left),minimum(temp->right)-temp->data);
	
	return temp;
}

struct node* right_rotate(struct node *node){
	struct node* x=node->left;
	struct node* y=x->right;
	x->right=node;
	node->left=y;

	node->height=1+max(height(node->left),height(node->right));
	x->height=1+max(height(x->left),height(x->right));

	node->count=1+(count(node->left)+count(node->right));
	x->count=1+count(x->left)+count(x->right);

	node->sum=node->data+presum(node->left)+presum(node->right);
	x->sum=x->data+presum(x->left)+presum(x->right);

	node->min=min(node->data,minimum(node->left),minimum(node->right));
	x->min=min(x->data,minimum(x->left),minimum(x->right));	

	node->max=maxi(node->data,maximum(node->left),maximum(node->right));
	x->max=maxi(x->data,maximum(x->left),maximum(x->right));

	node->mingap=mini(mingap(node->left),mingap(node->right),node->data-maximum(node->left),minimum(node->right)-node->data);
	x->mingap=mini(mingap(x->left),mingap(x->right),x->data-maximum(x->left),minimum(x->right)-x->data);	
	
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
	root->count=1+count(root->left)+count(root->right);
	root->sum=root->data+presum(root->left)+presum(root->right);
	root->min=min(minimum(root->left),minimum(root->right),root->data);
	root->max=maxi(maximum(root->left),maximum(root->right),root->data);
	root->mingap=mini(mingap(root->left),mingap(root->right),root->data-maximum(root->left),minimum(root->right)-root->data);

	int h=balance(root);
	if(h<-1 && key > root->right->data)	//RR case
		return left_rotate(root);

	if(h>1 && key < root->left->data)	//LL case
		return right_rotate(root);

	if(h>1 && key > root->left->data){	//LR case
		root->left=left_rotate(root->left);
		return right_rotate(root);
	}

	if(h<-1 && key < root->right->data){	//RL case
		root->right=right_rotate(root->right);
		return left_rotate(root);
	}

	return root;
}

void printpreorder(struct node *root){
	if(root!=NULL){
	printf("Element=%d count=%d sum=%d min=%d max=%d mingap=%d\n",root->data,root->count,root->sum,root->min,root->max,root->mingap);
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
	root->count=1+count(root->left)+count(root->right);
	root->sum=root->data+presum(root->left)+presum(root->right);
	root->min=min(minimum(root->left),minimum(root->right),root->data);
	root->max=maxi(maximum(root->left),maximum(root->right),root->data);
	root->mingap=mini(mingap(root->left),mingap(root->right),root->data-maximum(root->left),minimum(root->right)-root->data);
	
	int h=balance(root);
	if(h<-1 && key > root->right->data)	//RR case
		return left_rotate(root);

	if(h>1 && key < root->left->data)	//LL case
		return right_rotate(root);

	if(h>1 && root->left->data < key){	//LR case
		root->left=left_rotate(root->left);
		return right_rotate(root);
	}

	if(h<-1 && root->right->data > key){	//RL case
		root->right=right_rotate(root->right);
		return left_rotate(root);
	}

	return root;

}

int rank(struct node* root,int key){
	int r=0;
	struct node* temp=root;
	while(temp){
		if(temp->data < key)
			temp=temp->right;
		else{
			if(temp->right!=NULL){
				r=r+1+(temp->right->count);
			}else
				r=r+1;
			temp=temp->left;		
		}
	}
	if(search(root,key))
		return r;
	else
		return r+1;
}

int nth_Rank(struct node* root,int rank){
	struct node* temp=root;
	
	while(temp){
		int r=0;
		if(temp->right!=NULL)
			 r=temp->right->count;
		
		if(r+1==rank)
			return temp->data;
		else if(r+1<rank){
			rank=rank-(r+1);
			temp=temp->left;
		}
		else
			temp=temp->right;
	
	}
	return 0;
}

int prefixsum(struct node* root,int x){
	int sum=0;
	struct node* temp=root;
	while(temp){
		if(temp->data==x){
			if(temp->left)
				return sum+temp->left->sum+temp->data;
			else
				return sum+temp->data;
		}else if(temp->data<x){
			if(temp->left)
				sum=sum+temp->left->sum+temp->data;
			else
				sum=sum+temp->data;
			temp=temp->right;
		}else
			temp=temp->left;
			
	}
	return sum;
}

int range_mingap(struct node * root,int x,int y)
{
	if(root->data > y && root->data > x)
		return range_mingap(root->left,x,y);
	else if(root->data < x && root->data < y)
		return range_mingap(root->right,x,y);
	else if(root->data < x)
	{
		if(root->right)
			return range_mingap(root->right,x,y);
		else
			return INT_MAX;
	}
	else if(root->data > y)
	{
		if(root->left)
			return range_mingap(root->left,x,y);
		else
			return INT_MAX;
	}
	else
	{
		if(root->data==x)
		{
			if(root->right)
				return min2(range_mingap(root->right,x,y),root->right->min-root->data);
			else
				return INT_MAX;				
		}
		else if(root->data==y)
		{
			if(root->left)
				return min2(range_mingap(root->left,x,y),root->data-root->left->max);
			else
				return INT_MAX;				
		}
		else
		{
			if (root->left && root->right)
				return min(min2(range_mingap(root->left,x,y),range_mingap(root->right,x,y)),root->right->min-root->data,root->data-root->left->max);	
			else if(root->left)
				return min2(range_mingap(root->left,x,y),root->data-root->left->max);
			else if(root->right)
				return min2(range_mingap(root->right,x,y),root->right->min-root->data);
			else
				return INT_MAX;
		}
	}
}

void main(){
	struct node *root=NULL;
	root=insert(root,80);
	root=insert(root,70);
	root=insert(root,65);
	root=insert(root,50);
	root=insert(root,30);
	root=insert(root,25);
	root=insert(root,20);
	root=insert(root,10);
	root=insert(root,90);
	root=insert(root,100);
	root=insert(root,-99);
		
	printf("Element of tree:\n");
	printpreorder(root);
	struct node *temp=search(root,30);
	if(temp!=NULL)
		printf("There exist in the tree:%d\n",temp->data);
	else
		printf("not found in the tree\n");
	//root=delete(root,25);
	
	int r=rank(root,28);
	printf("Rank of the element28:%d\n",r);


	int nth_rank=nth_Rank(root,5);
	//printf("Element of tree:\n");
	//printpreorder(root);
	printf("5th rank element of array:%d\n",nth_rank);

	//number of element between two numbers
	printf("Number of element between 20 & 70:");
	int between_element=rank(root,20)-rank(root,70)-1;
	printf("%d\n",between_element);

	//Sum of all number <= given number
	printf("prefix sum of given number 50:");
	int pre_sum=prefixsum(root,49);
	printf("%d\n",pre_sum);
	
	//sum between two numbers 70&20
	printf("Sum of number between 20 & 70:");
	float bet_sum=prefixsum(root,70-1)-prefixsum(root,20);
	printf("%.1f\n",bet_sum);
	
	//avg between two numbers 70 & 20
	printf("Avg of all element between two numbers(20,70):");
	float avg=bet_sum/between_element;
	printf("%.2f\n",avg);
	
	//maxgap of the tree
	printf("maxgap of tree:");
	int maxgap=root->max-root->min;
	printf("%d\n",maxgap);

	//mingap of the tree
	printf("mingap of tree:");
	printf("%d\n",root->mingap);
	printf("range_mingap of tree:");
	int range=range_mingap(root,10,90);
	printf("%d\n",range );

}
