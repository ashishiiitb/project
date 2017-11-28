#include<stdio.h>
#include<stdlib.h>
int max=100;
int stack[100];
int top=-1;
int bottom=0;
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

int dequeue(){
	int data;
	data=stack[bottom];
	bottom=bottom+1;
	return data;
}

void main(){
	int A[]={1,2,3,6,5,25,7,5,2,9,10};
	
	int n=11;
	int l=3;
	int i=0;
	push(0);
	for(int j=1;j<l;j++){
		while(A[j] < A[stack[top]] && top >=bottom){
			pop();		
		}
		push(j);
			
	}
	
	int max=A[stack[top]]-A[stack[bottom]];
		
	for(int j=l;j<n;j++){
		
		while(A[j] < A[stack[top]] && top >=bottom){
			pop();
		}
		push(j);
		if(stack[top]-stack[bottom] == l){
			dequeue();
		}
		if(max < A[stack[top]]-A[stack[bottom]]){
			max=A[stack[top]]-A[stack[bottom]];
		}
		
			
			
	}
	printf(" maximum=%d ",max);
	
	
	
	
	
}
