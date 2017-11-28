#include<stdio.h>
#include<stdlib.h>
struct node{
	float weight;
	float profit;
	float avg;
};

void printarr(struct node arr[],int n){
	for(int i=0;i<n;i++){
		printf("%.2f    %.2f     %.2f\n",arr[i].weight,arr[i].profit,arr[i].avg);
	}
	
}

void insert(float p,float w,struct node arr[]){
	static int i=0;
	arr[i].weight=w;
	arr[i].profit=p;
	arr[i].avg=p/w;
	i++;
}


void sort_arr(struct node arr[],int n){
	for(int j=0;j<n-1;j++){
		for(int k=0;k<n-j-1;k++){
			if(arr[k].avg < arr[k+1].avg){
				struct node temp;
				temp=arr[k];
				arr[k]=arr[k+1];
				arr[k+1]=temp;
			}
		}
	}
	
}

void main(){
	int n=7;
	//printf("Enter the number of object in bag:");
	//scanf("%d",&n);
	struct node arr[n];
	insert(10,2,arr);
	insert(5,3,arr);
	insert(15,5,arr);
	insert(7,7,arr);
	insert(6,1,arr);
	insert(18,4,arr);
	insert(3,1,arr);
	/*for(int i=0;i<n;i++){
		float w,p;
		scanf("%f %f",&w,&p);
		insert(p,w,arr);
	}*/
	sort_arr(arr,n);
	printf("weight   profit   avg\n");
	printarr(arr,n);
	float m=15,profit=0;
	for(int i=0;i<n;i++){
		if(m>0 && arr[i].weight<=m){
			m=m-arr[i].weight;
			profit=profit+arr[i].profit;
			
		}else if(m>=0){
			profit=profit+arr[i].avg*m;
			break; }
		
	}
	printf("Total profit:%.2f",profit);
	
	
}
