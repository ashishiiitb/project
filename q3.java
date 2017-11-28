//if array is already sorted then find sum=X;---O(n);

import java.util.*;
public class q3{
	public static void main(String args[]){
		int arr[]={1,2,3,4,15,16,17};
		int len=arr.length;
		Scanner sc=new Scanner(System.in);
		int x=sc.nextInt();
		int i=0,flag=0;
		int j=len-1;
		while(i < j){
			if(arr[i]+arr[j] == x){
				flag=1;
				System.out.println("found");
				break;
			}else if(arr[i]+arr[j] > x){
				j--;
			}else
				i++;	
		}
		if(flag == 0)
			System.out.println("NOT FOUND");
	}
}
