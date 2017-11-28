#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int L[26][26];

int max(int a,int b){
	if(a > b)
		return a;
	else
		return b;
}
int lcs(char *str1,char *str2){
	int n=strlen(str1);
	
	int m=strlen(str2);
	
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			if(i==0 || j==0)
				L[i][j]=0;
			else if(str1[i-1] == str2[j-1])
				L[i][j]=L[i-1][j-1]+1;
			else
				L[i][j]=max(L[i-1][j],L[i][j-1]);
		}
	}

	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			printf("%d ",L[i][j] );

		}
		printf("\n");
	}

	return L[n][m];

}
void backtrack(char *str1,char *str2){
	int n=strlen(str1);
	int m=strlen(str2);
	char arr[(n>m?n:m)];
	int i=n,j=m,k=0;
	while(i>=0 && j>=0){
		if(str1[i]==str2[j]){
			arr[k]=str1[i];
			k++;
			i--;
			j--;
		}else{
			if(L[i][j]==L[i][j-1])
				j--;
			else
				i--;
		}
	}
	for(int i=(n>m?n:m)-1;i>=0;i--)
		printf("%c",arr[i] );
}

void main(){
	char str1[26]="bdcaba",str2[26]="abcbdab";
	/*printf("Enter the 1st string=");
	scanf("%s",str1);
	printf("Enter the 2nd string=");
	scanf("%s",str2);
	*/int res=lcs(str1,str2);
	
	printf("The longest common subsequence: %d\n",res);
	printf("Common substring is: " );
	backtrack(str1,str2);	
}
