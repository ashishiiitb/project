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
	int A[]={1,-2,3,-5,2,-9,10};
	
	int n=sizeof(A)/sizeof(int);
	int l=4;
	int i=0;
	int temp[n+1];
	temp[0]=0;
	for(int i=1;i<n+1;i++){
		temp[i]=temp[i-1]+A[i-1];
	}
	for(int i=0;i<n+1;i++){
		printf(" %d",temp[i]);
	}
	push(0);
	for(int j=1;j<l;j++){
		while(temp[j] < temp[stack[top]] && top >=bottom){
			pop();		
		}
		push(j);
			
	}
	
	int max=temp[stack[top]]-temp[stack[bottom]];
		
	for(int j=l;j<n+1;j++){
		
		while(temp[j] < temp[stack[top]] && top >=bottom){
			pop();
		}
		push(j);
		if(stack[top]-stack[bottom] == l){
			dequeue();
		}
		if(max < temp[stack[top]]-temp[stack[bottom]]){
			max=temp[stack[top]]-temp[stack[bottom]];
		}
		
			
			
	}
	printf(" maximum=%d ",max);
	
	
	
	
	
}
