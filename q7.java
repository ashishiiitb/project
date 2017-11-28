//find max diff of two element-O(n)

import java.util.*;
import java.math.*;
public class q7{
	public static void main(String args[]){
		int arr[]={1,32,3,41,0};
		int len=arr.length;
		int max=arr[0];
		int min=arr[0];
		for(int i=1;i<len;i++){
			if(arr[i]>max)
				max=arr[i];
			if(arr[i]<min)
				min=arr[i];
					
		}
		
		System.out.println(Math.abs(max-min));
		
	}
}
