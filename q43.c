#include<stdio.h>
#include<stdlib.h>



void main(){
	int coin[]={1,10,25};
	int n=14;
	int arr[n+1];
	for(int i=0;i<=n;i++)
		arr[i]=i;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<3;j++){
			if(i>=coin[j] && arr[i]>1+arr[i-coin[j]])
				arr[i]=1+arr[i-coin[j]];
		}
	}
	printf("minimum number of coin required:%d\n",arr[n]);
	
	/*	for(int j=0;j<n+1;j++)
			printf("%d ",arr[j]);
		printf("\n");
	*/
}
