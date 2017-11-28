//find min diff of two element-O(nlogn)
import java.util.*;
import java.math.*;
public class q9{
	public static void main(String args[]){
		int arr[]={1,32,3,41,20};
		Arrays.sort(arr);
		int len=arr.length;
		
		int min=arr[1]-arr[0];
		for(int i=2;i<len;i++){
			if(Math.abs(arr[i]-arr[i-1])<min)
				min=Math.abs(arr[i]-arr[i-1]);	
		}
	System.out.println(min);
	}
}
