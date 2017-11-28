import java.util.*;
import java.math.*;
public class q11{
	public static void main(String args[]){
		int arr[]={-1,32,-33,41,11,-30,-20};
		
		int len=arr.length;
		
		int m=0;
		for(int i=0;i<len;i++){
			
			int sum=arr[i];
			for(int k=i+1; k < len; k++){
				sum=sum+arr[k];				
				if(sum > m)
					m=sum;
			}
		}
		System.out.println(m);
	
	}
}
