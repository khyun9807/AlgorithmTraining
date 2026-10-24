import java.util.*;

public class Main {
    static int len=0;
    static ArrayList<Integer>[] graph=null;
    static boolean[] isDone=null;
    static ArrayDeque<Integer> st=null;

    static void dfs(int cur){
        if(isDone[cur])return;
        ArrayList<Integer> neighbors=graph[cur];

        //boolean isDeadend=true;
        for(int neighbor : neighbors){
            if(isDone[neighbor])continue;

            //isDeadend=false;

            dfs(neighbor);
        }

        //if(isDeadend)
        {
            isDone[cur]=true;
            st.addLast(cur);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        len=n;
        graph=new ArrayList[n];
        for(int i=0;i<n;i++)graph[i]=new ArrayList<>();
        int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();--a;
            int b = sc.nextInt();--b;

            graph[a].add(b);
        }

        isDone=new boolean[n];
        Arrays.fill(isDone,false);
        st=new ArrayDeque<>();

        for(int i=0;i<n;i++){
            dfs(i);
        }

        while(!st.isEmpty()){
            System.out.print((st.peekLast()+1)+" ");
            st.removeLast();
        }
    }
}