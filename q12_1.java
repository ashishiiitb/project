import java.util.*;
import java.math.*;
public class q12_1{
	public static void main(String args[]){
		int arr[]={-1,2,-3,11,-20};
		
		int len=arr.length;
		int max=Integer.MIN_VALUE,sum=0;
		//System.out.println(max);
		for(int i=0;i<len;i++){
			
			sum=sum+arr[i];
			if(max < sum)
				max=sum;
			if(sum < 0)
				sum=0;
			
		}
		System.out.println(max);
	
	}
}
