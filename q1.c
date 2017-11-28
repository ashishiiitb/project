//find sum of 2 element in array=X;--o(n^2)
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int x;
	scanf("%d",&x);
	int flag=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(arr[i]+arr[j] == x){
				flag=1;
				break;
			}	
					
		}	
	}
	if(flag == 1)
		printf("\nYES");
	else
		printf("\nNO");
}
