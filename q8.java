//find min diff of two element-O(n^2)

import java.util.*;
import java.math.*;
public class q8{
	public static void main(String args[]){
		int arr[]={1,32,3,41,6};
		int len=arr.length;
		int min=Math.abs(arr[1]-arr[0]);
		for(int i=0;i<len;i++){
			for(int j=0;j<len;j++){
				if(i != j){
					if(Math.abs(arr[j]-arr[i])<min)
						min=Math.abs(arr[j]-arr[i]);
				}
			}
					
		}
		
		System.out.println(min);
		
	}
}
