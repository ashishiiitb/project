#include<stdio.h>
#include<stdlib.h>
void main(){
	int arr[]={1,1,1,0};
	int j;
	j=sizeof(arr)/sizeof(int);
	//printf("%d",j);
	j=j-1;
	int i=0;
	int count=0;
	while(i < j){
		if(arr[i] == 1 && count == 0){
			count++;
			i++;
		}else{
			while(arr[i] == 0 && i < j){
				i++;
			}
			if(arr[i] == 1 && count == 0){
			count++;
			i++;
			}
		}
		if(arr[j] == 0 && count == 1){
			count--;
			j--;
		}else{
			while(arr[j] == 1 && i < j){
				j--;
			}
			if(arr[j] == 0 && count == 1){
			count--;
			j--;
			}
		}
	}
	if(count == 0)
		printf("%d",i);


}
