import java.util.*;

class Solution {
    int nlen=0;
    int answer=0;
    int[][]graph=null;
    
    boolean[] isVisited=null;
    
    void dfs(int now){
        if(isVisited[now])return;
        isVisited[now]=true;
        
        int[]isConnected=graph[now];
        for(int neighbor=0;neighbor<nlen;neighbor++){
            if(isConnected[neighbor]==1&&!isVisited[neighbor]){
                dfs(neighbor);
            }
        }
    }
    
    void func(){
        for(int i=0;i<nlen;i++){
            if(isVisited[i])continue;
            
            dfs(i);++answer;
        }
    }
    
    public int solution(int n, int[][] computers) {
        nlen=n;
        isVisited=new boolean[nlen];
        Arrays.fill(isVisited,false);
        graph=new int[nlen][];
        for(int i=0;i<nlen;i++){
            graph[i]=Arrays.copyOf(computers[i],nlen);
        }
        
        func();
        
        return answer;
    }
}