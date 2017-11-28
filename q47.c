#include<stdio.h>
#include<stdlib.h>

int matrixmulti(int p[],int i,int j){
	if(i==j)
		return 0;
	int k;
	int min=99999;
	int count;
	for(int k=i;k<j;k++){
		count=matrixmulti(p,i,k)+matrixmulti(p,k+1,j)+p[i-1]*p[k]*p[j];
		if(count<min)
			min=count;
	}
	return min;

}

void main(){
	int p[]={1,2,1,4,1};
	int n=sizeof(p)/sizeof(p[0]);
	int min=matrixmulti(p,1,n-1);
	printf("%d",min);

}
