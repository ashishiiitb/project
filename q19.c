#include<stdio.h>
#include<stdlib.h>
void main(){
	int A[]={3,6,8,7,5,2,9,10};
	
	int n=8;
	int k=3;
	
	for(int i=0;i <= n-k;i++){
		int min=A[i];
		for(int j=i;j<i+k;j++){
			if(A[i] > A[j])
				min=A[j];
		}
		printf("%d ",min);	
	}
	
}
