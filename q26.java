import java.util.*;
import java.math.*;
public class q26{
	public static void main(String args[]){
		int arr[]={-1,32,3,41,12,-20,12,53};
		
		int len=arr.length;
		int[] temp=new int[len+1];
		for(int i=0;i<len+1;i++){
			temp[i]=0;		
		}
		temp[0]=0;
		int m=0;
		for(int i=1;i<len+1;i++){
			temp[i]=temp[i-1]+arr[i-1];
		}
		for(int i=0;i<len+1;i++){
			System.out.print(" "+temp[i]);
		}
		System.out.println("\n=========");
		int i=0;
		int l=3;
		int j=l;
		int max=temp[l]-temp[i];
		
		while(j < len+1){
			if(temp[i] > temp[j-l])
				i=j-l;
			if(temp[j]-temp[i] > max)
				max=temp[j]-temp[i];
			j++;
			//System.out.println(" max="+max);
		}
		System.out.println(" max="+max);
	
	}
}
