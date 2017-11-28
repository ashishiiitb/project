import java.util.*;
import java.math.*;
public class q12{
	public static void main(String args[]){
		int arr[]={-1,32,3,41,-20};
		
		int len=arr.length;
		int[] temp=new int[len];
		for(int i=0;i<len;i++){
			temp[i]=0;		
		}
		temp[0]=arr[0];
		int m=0;
		for(int i=1;i<len;i++){
			temp[i]=temp[i-1]+arr[i];
		}
		
		int max=temp[1]-temp[0];
		int i=0,j=1;
		while(j < len){
			if(temp[i] > temp[j-1])
				i=j-1;
			if(temp[j]-temp[i] > max)
				max=temp[j]-temp[i];
			j++;
		}
		System.out.println(max);
	
	}
}
