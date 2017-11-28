//find sum of 2 element in array=X;--O(nlogn)
import java.util.*;
public class q2{
	public static int Bsearch(int arr[],int i,int j,int find){
		if(i<j){
			int mid=i+(j-i)/2;
		if(arr[mid] == find)
			return mid;
		else if(arr[mid] > find)
			return(Bsearch(arr,0,mid-1,find));
		else
			return(Bsearch(arr,mid+1,j,find));
		}
	return -1;
	}
	public static void main(String args[]){
		int arr[]={12,10,5,22,45};
		int len=arr.length;
		Arrays.sort(arr);
		System.out.println("enter the sum of two element");
		Scanner scan=new Scanner(System.in);
		int x=scan.nextInt();
		int flag=0;
		for(int i=0;i<len;i++){
			int res=Bsearch(arr,0,len,x-arr[i]);
			if(res != -1){
			flag=1;
			System.out.println("sum is found="+arr[i]+"+"+arr[res]);
			
			break;
			}
		}
		if(flag == 0)
			System.out.println("sum in not found");
			
	}
}
