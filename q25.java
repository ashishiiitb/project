import java.util.*;
import java.math.*;
public class q25{
	public static void main(String args[]){
		int arr[]={-1,32,3,41,-20,12,53};
		
		int len=arr.length;
		int[] temp=new int[len+1];
		for(int i=0;i<len;i++){
			temp[i]=0;		
		}
		temp[0]=0;
		int m=0;
		for(int i=1;i<len;i++){
			temp[i]=temp[i-1]+arr[i];
		}
		int i=0;
		int l=3;
		int j=l;
		int max=temp[l]-temp[i];
		
		while(j < len){
			
			if(temp[j]-temp[i] > max)
				max=temp[j]-temp[i];
			j++;
			i++;
		}
		System.out.println(max);
	
	}
}
