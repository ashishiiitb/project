#include<stdio.h>
#include<stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort5(int arr[],int k,int l){
	int i;
	for (i = k; i < l-1; i++){     
		for (int j = k; j < l-i-1; j++){
	             if (arr[j] > arr[j+1])
              		swap(&arr[j], &arr[j+1]);
		}
	}
}

int  deter(int arr,int n){
	int i=0;
	while(i<n){
		sort5(arr,i,i+5);
		i=i+5;
	}
	return 0;
}


int main(){
	int n;
	//scanf("%d",&n);
	int arr[10]={3,2,7,1,5,9,6,11,23,45};
	//for(int i=0;i<n;i++){
	//scanf("%d",&arr[i]);	
	//}
	n=10;
	int res=deter(arr,n);
	for(int i=0;i<n;i++)
	printf("%d",arr[i]);
}
