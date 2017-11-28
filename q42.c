#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
	return(a<b)?a:b;
}

void main(){
	int coin[]={1,10,7};
	int n=14;
	int arr[3][n+1];
	for(int i=0;i<3;i++){
		arr[i][0]=0;
	}
	for(int i=0;i<n+1;i++){
		arr[0][i]=i;
	}
	for(int i=1;i<3;i++){
		for(int j=1;j<n+1;j++){
			if(j<coin[i])
				arr[i][j]=arr[i-1][j];
			else
				arr[i][j]=min(arr[i-1][j],arr[i][j-coin[i]]+1);
		}
	}
	printf("minimum number of coin required:%d\n",arr[2][14]);
	/*for(int i=0;i<3;i++){
		for(int j=0;j<n+1;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}*/
}
