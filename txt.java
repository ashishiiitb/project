import java.util.*;

public class txt {
    public static void main(String[] args) {
        String s="abacdgdcaba";
        int len=s.length();
        boolean arr[][]=new boolean[len][len];
        int i,j;
        for(i=0;i<len;i++){
            for(j=0;j<len;j++){
                arr[i][j]=false;
            }
        }
        for(i=0;i<len;i++){
            arr[i][i]=true;
        }
        int st=0,count=0;
        for(i=0;i<len-1;i++){
            if(s.charAt(i)==s.charAt(i+1)){
                st=i;
                count=2;
                arr[i][i+1]=true;
            }
        }
        int k;
        for(k=2;k<len;k++){
            
            for(i=0;i<len-k;i++){
                j=k+i;
                if(arr[i+1][j-1] && s.charAt(i)==s.charAt(j)){
                    arr[i][j]=true;
                    st=i;
                    if(count<j-i+1)
                        count=j-i+1;
                }
            }
        }
        System.out.println(count);
        System.out.println(st);
        String res=s.substring(st,st+count);
        System.out.println(res);
    }
}