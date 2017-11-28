#include<stdio.h>
#include<stdlib.h>
int longest(int arr[],int n){
	int lis[n];
	for(int i=0;i<n;i++){
		lis[i]=1;	
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j] < arr[i] && lis[j]+1 > lis[i])
				lis[i]=lis[j]+1;		
		}
	}
	int max=0;
	
	for(int i=0;i<n;i++){
		if(max<lis[i])
			max=lis[i];	
	}
	return max;
	
}
void main(){
	int n;
	printf("Enter the number of element in array\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the element of array\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int res=longest(arr,n);
	printf("%d",res);

}
