#include<stdio.h>
#include<stdlib.h>


void main(){
	int subset[]={6,3,2,1};
	int n=9;
	//size of subset
	int m=4;
	int  arr[m+1][n+1];
	for(int i=0;i<=m;i++){
		arr[i][0]=1;
	}
	for(int i=1;i<n+1;i++){
		arr[0][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<n+1;j++){
			if(j<subset[i-1])
				arr[i][j]=arr[i-1][j];
			else
				arr[i][j]=arr[i-1][j] | arr[i-1][j-subset[i-1]];
		}
	}
	if(arr[m][n]==1)
		printf("subset posible\n");
	else
		printf("Not posible");
	/*for(int i=0;i<=m;i++){
		for(int j=0;j<n+1;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}*/
}
