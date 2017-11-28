#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b){
	return (a>b)?a:b;
}

void main(){
	char str[]="cabvbma";
	int n=strlen(str);
	int arr[3][n];
	for(int i=0;i<3;i++)
		for(int j=0;j<n;j++)
			arr[i][j]=0;

	for(int i=0;i<n;i++){
		arr[0][i]=1;
	}
	for(int i=0;i<n-1;i++){
		if(str[i+1]==str[i]){
			arr[1][i]=2;
		}else
			arr[1][i]=1;
	}

	/*for(int i=2;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(str[i]==str[j])
				arr[i%3][j]=2+arr[(i-2)%3][j+1];
			else
				arr[i%3][j]=max(arr[(i-1)%3][j],arr[(i-1)%3][j-1]);
		}
	}*/

	for(int l=2;l<n;l++){
		for(int i=0;i<n-l;i++){
			int j=i+l;
			if(str[i]==str[j])
				arr[l%3][i]=2+arr[(l+1)%3][i+1];
			else
				arr[l%3][i]=max(arr[(l-1)%3][i],arr[(l-1)%3][i+1]);
		}
	}

	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr[i][j] );

		}
		printf("\n");
	}
	
	
	printf("The lenght of longest palindrome subsequence: %d\n",arr[(n-1)%3][0] );
	
	
	
}



