import java.util.*;
import java.math.*;

public class q23{
	public static void main(String args[]){
		int arr[]={71,32,3,41,20,10,100};
		
		int len=arr.length;
		int l=3;
		int i=0,j=l;
		int max=arr[l]-arr[0];
		
		while(j < len){
			
			
			if(arr[j]-arr[i] > max)
				max=arr[j]-arr[i];
			
			
			j++;
			i++;
		}
	System.out.println(max);
	}
}
