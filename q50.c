#include <stdio.h>
#include <stdlib.h>
int min(int a,int b){
	return (a<b)?a:b;
}
void main(){
	int n=5;
	int k=2;
	int arr[n+1][k+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<min(i+1,k+1);j++){
			if(j==0)
				arr[i][j]=1;
			else if(i==j)
				arr[i][j]=1;
			else
				arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
		}
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<min(k+1,n+1);j++){
			printf("%d ",arr[i][j] );

		}
		printf("\n");
	}
	printf("Binomial coeffeicent: %d\n",arr[n][k] );
}