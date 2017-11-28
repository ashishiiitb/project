import java.util.*;
public class q5{
	public static void main(String args[]){
		int arr[]={1,2,123,24,5};
		Arrays.sort(arr);
		int len=arr.length;
		int flag=0;
		for(int k=0;k<len;k++){
			int i=0;
			int j=len-1;
			int x=arr[k];
			while(i < j){
			if(arr[i]+arr[j] == x){
				flag=1;
				//System.out.println("found");
				break;
			}else if(arr[i]+arr[j] > x){
				j--;
			}else
				i++;	
		}
		
		
	}
	if(flag == 0)
		System.out.println("NOT FOUND");		
	else
		System.out.println("found");	
}
}
