#include<stdio.h>
#include<stdlib.h>
struct node{
	int  deadline;
	int profit;
};

void printarr(struct node arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d    %d\n",arr[i].profit,arr[i].deadline);
	}
	
}

void insert(int p,int d,struct node arr[]){
	static int i=0;
	arr[i].deadline=d;
	arr[i].profit=p;
	i++;
}
int min(int a,int b){
	return a<b?a:b;
}


void sort_arr(struct node arr[],int n){
	for(int j=0;j<n-1;j++){
		for(int k=0;k<n-j-1;k++){
			if(arr[k].profit < arr[k+1].profit){
				struct node temp;
				temp=arr[k];
				arr[k]=arr[k+1];
				arr[k+1]=temp;
			}
		}
	}
	
}

int minvalue(int x, int y) {
	if(x < y) return x;
	return y;
}

void jobsequence(struct node arr[],int n){
	int profit=0;
	
	int max=0;
	for(int i=0;i<n;i++){
		if(max<arr[i].deadline)
			max=arr[i].deadline;
	}
	printf("Maximum deadline:%d\n",max);
	int total[max],l=0;
	for(int i=0;i<max;i++)
		total[i]=0;
	for(int i=0;i<n;i++){
		for(int j=min(n,arr[i].deadline)-1;j>=0;j--){
			if(total[j]==0){
				total[j]=arr[i].profit;
		printf("%d %d\n",total[j],i );
				break;
			}
		}
	}
	for(int i=0;i<max;i++){
		
		profit=profit+total[i];
	}
	printf("Total profit:%d",profit);
}

void main(){
	int n=9;
	struct node arr[n];
	insert(15,7,arr);
	insert(20,2,arr);
	insert(30,5,arr);
	insert(18,3,arr);
	insert(18,4,arr);
	insert(10,5,arr);
	insert(23,2,arr);
	insert(16,7,arr);
	insert(25,3,arr);
	sort_arr(arr,n);
	printf("profit   deadline\n");
	printarr(arr,n);
	jobsequence(arr,n);
	
	
	//printf("Total profit:%.2f",profit);
	
	//printf("Total profit:%.2f",max);
	
}
