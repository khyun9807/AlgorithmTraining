import java.util.*;

public class Main {

    public static void func(int k,int n, String str){
        if(n==0){
            System.out.println(str);
            return;
        }
        for(int i=1;i<=k;i++){
            String s=str+(i+" ");
            func(k,n-1,s);
        }

        return;
    }

    public static void main(String[] args) {
        // Please write your code here.
        Scanner sc=new Scanner(System.in);

        int k=sc.nextInt();
        int n=sc.nextInt();

        func(k,n,"");
    }
}