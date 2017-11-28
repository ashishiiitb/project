#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int a,int b,int c){
	if(a<b){
		if(a<c)
			return a;
		else
			return c;
	}else{
		if(b<c)
			return b;
		else
			return c;
	}
}

int editdistance(char str1[],char str2[]){
	int n=strlen(str1);
	int m=strlen(str2);
	int arr[n+1][m+1];
	for(int j=0;j<m+1;j++)
		arr[0][j]=j;
	for(int i=0;i<n+1;i++)
		arr[i][0]=i;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(str1[i-1]==str2[j-1])
				arr[i][j]=arr[i-1][j-1];
			else
				arr[i][j]=1+min(arr[i-1][j],arr[i-1][j-1],arr[i][j-1]);
		}
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			printf("%d ",arr[i][j] );

		}
		printf("\n");
	}
	return arr[n][m];
}

void main(){
	char str1[10]="cart";
	char str2[20]="march";
	//scanf("%s",str1);
	//scanf("%s",str2);
	int mini=editdistance(str1,str2);
	printf("minimum number of opration required: %d\n",mini );
	//printf("%d\n",min(0,1,1) );

}