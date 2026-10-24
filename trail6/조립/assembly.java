import java.util.*;
public class Main {
    static int[][]graph=null;
    static int n=0;

    static int[][]results=null;
    static boolean[] isMin=null;
    static int[] func(int target){
        //System.out.println(target+1);
        if(isMin[target]){
            results[target][target]=1;
            return results[target];
        }
        int[] targetNeighborInfo=graph[target];

        for(int neighbor=0;neighbor<n;neighbor++){
            int neighborCnt=targetNeighborInfo[neighbor];

            if(neighborCnt==0)continue;

            results[target][neighbor]=0;

            int[] neighborResult=func(neighbor);
            for(int i=0;i<n;i++){
                results[target][i]+=neighborCnt*results[neighbor][i];
            }
        }

        return results[target];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        graph=new int[n][n];
        results=new int[n][n];
        int m = sc.nextInt();
        isMin=new boolean[n];
        Arrays.fill(isMin,true);
        // Please write your code here.
        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();--x;//목적
            int y = sc.nextInt();--y;//재료
            int z = sc.nextInt();//갯수

            graph[x][y]=z;
            results[x][y]=z;
            isMin[x]=false;
        }

        int[] answer=func(n-1);

        for(int i=0;i<n;i++){
            int a=answer[i];
            if(a==0)continue;
            System.out.println((i+1)+" "+a);
        }
    }
}