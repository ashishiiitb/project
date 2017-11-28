import java.util.*;
public class q17{
	public static void main(String args[]){
		int arr[]={3,6,8,7,5,2,9,10};
		int len=arr.length;
		int b[]=new int[len];
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				if(arr[j] < arr[i]){
					b[i]=j;
					break;
				}
				if(j == len-1)
					b[j]=0;
			}
		}
		for(int i=0;i<len;i++){
			System.out.print(" "+b[i]);
		}
	}
}
