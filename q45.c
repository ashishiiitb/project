#include<stdio.h>
#include<stdlib.h>

void main(){
	int weight[]={2,1,3,2};
	int value[]={12,10,21,15};
	int n=8;
	int m=4;
	int arr[n+1];
	
	for(int i=0;i<n+1;i++){
		if(weight[0]>i)
			arr[i]=0;
		else
			arr[i]=value[0];
	}

	for(int i=1;i<m;i++){
		for(int j=n;j>=0;j--){
			if(j>=weight[i] && arr[j]<value[i]+arr[j-weight[i]])
				arr[j]=value[i]+arr[j-weight[i]];
		}
	}
	printf("maximum profit of knapsack:%d\n",arr[n]);
	
		for(int j=0;j<n+1;j++)
			printf("%d ",arr[j]);
		printf("\n");
	
}
