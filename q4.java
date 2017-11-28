//sum of two element in array exist or not in same array-O(n^3);

import java.util.*;
public class q4{
	public static void main(String args[]){
		int arr[]={11,22,33,90,50,16,7};
		int len=arr.length;
		int flag=0;
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				for(int k=0;k<len;k++){
					if(arr[i]+arr[j]==arr[k]){
						flag=1;
						break;
					}				
				}			
			}		
		}
		if(flag == 0)
			System.out.println("NOT EXIST");
		else
			System.out.println("EXIST");
	}
}
