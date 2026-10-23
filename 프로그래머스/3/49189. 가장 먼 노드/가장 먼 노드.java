import java.util.*;

class Solution {
    ArrayList<Integer>[] g=null;
    int len=0;
    public int solution(int ni, int[][] edge) {
        len=ni;
        boolean[] isReserved=new boolean[len];
        Arrays.fill(isReserved,false);
        g=new ArrayList[len];
        for(int i=0;i<len;i++){
            g[i]=new ArrayList<>();
        }
        ArrayDeque<int[]> que=new ArrayDeque<>();//a w
        for(int[]e:edge){
            int a=e[0];
            int b=e[1];
            --a;--b;
            g[a].add(b);
            g[b].add(a);
        }
        
        que.addLast(new int[]{0,0});
        isReserved[0]=true;
        ArrayList<int[]> results=new ArrayList<>();
        while(!que.isEmpty()){
            int[] cur=que.peekFirst();
            que.removeFirst();
            int a=cur[0];
            int w=cur[1];
            
            ArrayList<Integer> neighbor=g[a];
            boolean isDeadend=true;
            for(int n : neighbor){
                if(isReserved[n])continue;
                isReserved[n]=true;
                que.addLast(new int[]{n,w+1});
                isDeadend=false;
            }
            
            if(isDeadend){
                results.add(new int[]{a,w});
            }
        }
        
        Collections.sort(results,(a,b)->{
            return Integer.compare(b[1],a[1]);
        });
        
        int answer = 0;
        int val=(results.get(0))[1];
        for(int[] a:results){
            if(val==a[1]){
                ++answer;
            }
            else{
                break;
            }
        }        
        
        return answer;
    }
}