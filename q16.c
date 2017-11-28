#include<stdio.h>
#include<stdlib.h>
int max=10;
int stack[10];
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
	push(3);
	push(4);
	
	push(3);
	push(4);
	
	push(3);
	push(4);
	
	push(3);
	push(4);
	
	push(3);
	printf("\ntop element=%d\n",stack[top]);
	
	push(3);
	push(14);
	
	push(3);
	push(14);

	int data=pop();
	printf("%d ",data);
	while(top != -1){
		int data=pop();
		printf("%d ",data);
	}
	pop();
}
