import java.util.*;
import java.math.*;
public class q10{
	public static void main(String args[]){
		int arr[]={-1,32,-33,41,11,-30,-20};
		
		int len=arr.length;
		
		int m=0;
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				int sum=0;
				for(int k=i; k <= j; k++){
					sum=sum+arr[k];
				}
				if(sum > m)
					m=sum;
			}
		}
		System.out.println(m);
	
	}
}
