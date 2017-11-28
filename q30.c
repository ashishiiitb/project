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

struct node* buildtree(int in[],int pre[],int start,int end){
	static int preindex=0;
	if(start>end)
		return NULL;
	struct node *node=newnode(pre[preindex++]);
	if(start == end)
		return node;
	int index=search(in,start,end,node->data);
	node->left=buildtree(in,pre,start,index-1);
	node->right=buildtree(in,pre,index+1,end);
	return node;

}
void postorder(struct node* root){
	if(root == NULL)
		return ;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}



void main(){
	int in[]={5,4,15,3,52,12,23};
	int pre[]={3,4,5,15,12,52,23};
	int len=sizeof(in)/sizeof(int);
	struct node *root=buildtree(in,pre,0,len-1);
	printf("Postorder traversal\n");
	postorder(root);
	
}
