#include<stdio.h>
#include<stdlib.h>

int matrixmulti(int p[],int n){
	int arr[n][n];
	for(int i=1;i<n;i++)
		arr[i][i]=0;
	for(int l=2;l<n;l++){
		for(int i=1;i<n-l+1;i++){
			int j=i+l-1;
			arr[i][j]=99999;
		
			for(int k=i;k<j;k++){
				int count=arr[i][k]+arr[k+1][j]+p[i-1]*p[k]*p[j];
				if(count < arr[i][j])
					arr[i][j]=count;
			}
		}

	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}*/
	return arr[1][n-1];
}

void main(){
	int p[]={1,2,1,4,1};
	int n=sizeof(p)/sizeof(p[0]);
	int min=matrixmulti(p,n);
	printf("minimum number of requried multiplication: %d",min);


}
