#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
	return(a>b)?a:b;
}

void main(){
	int weight[]={1,4,2};
	int value[]={10,25,12};
	int n=6;
	int m=3;
	int arr[m][n+1];
	for(int i=0;i<m;i++){
		arr[i][0]=0;
	}
	for(int i=0;i<n+1;i++){
		if(weight[0]>i)
			arr[0][i]=0;
		else
			arr[0][i]=value[0];
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<n+1;j++){
			if(j<weight[i])
				arr[i][j]=arr[i-1][j];
			else
				arr[i][j]=max(arr[i-1][j],arr[i-1][j-weight[i]]+value[i]);
		}
	}
	printf("maximum profit of knapsack:%d\n",arr[m-1][n]);
	/*for(int i=0;i<4;i++){
		for(int j=0;j<n+1;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	*/
}
