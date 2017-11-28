#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int max(int a,int b){
	if(a > b)
		return a;
	else
		return b;
}
int lcs(char *str1,char *str2){
	int n=strlen(str1);
	
	int m=strlen(str2);
	//int l=n>m?n:m;
	int L[2][m+1];
	for(int i=0;i<m+1;i++)
		L[0][i]=0;
	L[1][0]=0;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			
			if(str1[i-1] == str2[j-1])
				L[i%2][j]=L[(i-1)%2][j-1]+1;
			else
				L[i%2][j]=max(L[(i-1)%2][j],L[i%2][j-1]);
		}
	}

	for(int i=0;i<2;i++){
		for(int j=0;j<m+1;j++){
			printf("%d ",L[i][j] );

		}
		printf("\n");
	}

	return L[n%2][m];

}


void main(){
	char str1[26]="bdcaba",str2[26]="abcbdab";
	/*printf("Enter the 1st string=");
	scanf("%s",str1);
	printf("Enter the 2nd string=");
	scanf("%s",str2);
	*/int res=lcs(str1,str2);
	
	printf("The longest common subsequence: %d\n",res);
		
}
