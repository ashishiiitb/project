#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *left;
	int data;
	struct node *right;

};
int search(int in[],int start,int end,int data){
	for(int i=start;i<=end;i++){
		if(data==in[i])
			return i;
	}
	return 0;
}

struct node* newnode(int data){
	struct node* node;
	node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

struct node* buildtree(int in[],int post[],int start,int end){
	int postindex=end;
	if(start>end)
		return NULL;
	struct node *node=newnode(post[postindex--]);
	if(start == end)
		return node;
	int index=search(in,start,end,(node->data);
	node->left=buildtree(in,post,start,index-1);
	node->right=buildtree(in,post,index+1,end);
	return node;

}
void preorder(struct node* root){
	if(root == NULL)
		return ;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
	
}



void main(){
	int in[]={5,4,15,3,52,12,23};
	int post[]={5,15,4,52,23,12,3};
	int len=sizeof(in)/sizeof(int);
	struct node *root=buildtree(in,post,0,len-1);
	printf("Preorder traversal\n");
	preorder(root);
	
}
