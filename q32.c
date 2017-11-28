#include<stdio.h>
#include<stdlib.h>
int countfriendpair(int n){
	int count[n+1];
	for(int i=0;i <= n;i++){
		if(i <= 2)
			count[i]=i;
		else
			count[i]=count[i-1]+(i-1)*count[i-2];	
	}
	return count[n];

}
void main(){
	int n;
	scanf("%d",&n);
	int res=countfriendpair(n);
	printf("number of ways %d",res);

}
