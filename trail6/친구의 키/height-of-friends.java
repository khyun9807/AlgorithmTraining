import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer>[] graph=new ArrayList[n];
        for(int i=0;i<n;i++)graph[i]=new ArrayList<>();

        int[] take=new int[n];
        Arrays.fill(take,0);

        int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();--a;
            int b = sc.nextInt();--b;

            take[b]++;
            graph[a].add(b);
        }


        ArrayDeque<Integer> que=new ArrayDeque<>();
        for(int i=0;i<n;i++){
            if(take[i]==0)que.addLast(i);
        }

        ArrayList<Integer> done=new ArrayList<>();
        while(!que.isEmpty()){
            int cur=que.peekFirst();
            que.removeFirst();

            done.add(cur);

            ArrayList<Integer> neighbors=graph[cur];
            for(int neighbor : neighbors){
                if(take[neighbor]==0)continue;
                take[neighbor]--;
                if(take[neighbor]==0)que.addLast(neighbor);
            }
        }

        for(int a : done){
            ++a;
            System.out.print(a+" ");
        }
        
    }
}