import java.util.*;
import java.math.*;
public class q14{
	public static void main(String args[]){
		int arr[]={71,32,3,41,20};
		
		int len=arr.length;
		
		int max=arr[1]-arr[0];
		int i=0,j=1;
		while(j < len){
			if(arr[i] > arr[j-1])
				i=j-1;
			if(arr[j]-arr[i] > max)
				max=arr[j]-arr[i];
			j++;
		}
	System.out.println(max);
	}
}
