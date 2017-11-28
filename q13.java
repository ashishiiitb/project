import java.util.*;
import java.math.*;
public class q13{
	public static void main(String args[]){
		int arr[]={-1,31,34,75,55};
		
		int len=arr.length;
		
		int max=0;
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				if(arr[j]-arr[i] >max)
					max=arr[j]-arr[i];
			}	
		}
	System.out.println(max);
	}
}
