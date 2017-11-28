#include<stdio.h>
#include<stdlib.h>
int max=100;
int stack[100];
int top=-1;

int pop(){
	int data;
	if(top != -1){
		data=stack[top];
		top=top-1;
		return data;	
	}else{
		printf("\ncould not retrive data ,stack is empty");	
	}

}

int push(int data){
	if(top != max){
		top=top+1;
		stack[top]=data;
	}else{
		printf("Could not insert data,stack is full.\n");
	}


}

void main(){
	int A[]={3,6,8,7,5,2,9,10};
	int B[8];
	int n=8;
	//int i=0;
	push(0);
	for(int j=1;j<n;j++){
		if(A[j] > A[stack[top]]){
			push(j);		
		}else{
			while(A[j] < A[stack[top]] && top >=0){
				B[pop()]=j;
			}
			push(j);		
		}	
	}
	while(top >= 0){
		B[pop()]=0;	
	}
	for(int j=0;j<n;j++)
		printf(" %d ",B[j]);
	
}
