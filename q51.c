#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b){
	return (a>b)?a:b;
}

void main(){
	char str[]="awcabvbmaa";
	int n=strlen(str);
	int arr[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr[i][j]=0;

	for(int i=0;i<n;i++){
		arr[i][i]=1;
	}
	for(int i=1;i<n;i++){
		if(str[i-1]==str[i]){
			arr[i-1][i]=2;
		}else
			arr[i-1][i]=1;
	}

	for(int l=2;l<n;l++){
		for(int i=0;i<n-l;i++){
			int j=i+l;
			if(str[i]==str[j])
				arr[i][j]=2+arr[i+1][j-1];
			else
				arr[i][j]=max(arr[i+1][j],arr[i][j-1]);
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr[i][j] );

		}
		printf("\n");
	}
	
	int l=arr[0][n-1];
	printf("The lenght of longest palindrome subsequence: %d\n",arr[0][n-1] );
	
	int i=0,j=n-1;
	char res[l];
	int count;
	printf("the result of backtracking: ");
	while(i<n && j>=0 && arr[i][j]>0){
		if(str[j]==str[i]){
			res[count]=str[i];
			count++;

			i++;
			j--;
		}else{
			if(arr[i][j]==arr[i][j-1])
				j=j-1;
			else
				i=i+1;
		}
	}
	for (int i = 0; i < l; ++i)
	{
		printf("%c",res[i] );
	}
	if(l%2==0){
		for (int i = count-1; i >=0; i--)
			printf("%c",res[i] );
	}else{
		for (int i = count-2; i >=0; i--)
		printf("%c",res[i] );
	
	}
	//printf("%d\n",i );
	/*while(i<n && j>=0){
		if(str[j]==str[i]){
			printf("%c",str[i]);
			i++;
			j--;
		}else{
			if(str[i+1]==str[j]){
				//printf("%c",str[j]);
				i=i+1;
			}	
			else if(str[i]==str[j-1]){
				//printf("%c",str[i]);
				j=j-1;
			}else{
				i++;
				j--;
			}
		}
	}*/
}



