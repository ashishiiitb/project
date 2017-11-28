//find max diff of two element-O(n^2)

import java.util.*;
import java.math.*;
public class q6{
	public static void main(String args[]){
		int arr[]={1,322,3,41,5};
		int len=arr.length;
		int max=0;
		for(int i=0;i<len;i++){
			
			for(int k=0;k<len;k++){
				if(Math.abs(arr[i]-arr[k]) > max){
					max=Math.abs(arr[i]-arr[k]);
				}				
							
			}		
		}
		
		System.out.println(max);
		
	}
}
