import java.util.*;

class Solution {      //0  1  2  3
                      //북 동 남 서
    int[] dy=new int[]{-1,0,1,0};
    int[] dx=new int[]{0,1,0,-1};

    int n;
    int m;
    boolean[][] reserved;
    class Node{
        public int y;
        public int x;
        public int c;
        public Node(int _y, int _x, int _c){
            y=_y;
            x=_x;
            c=_c;
        }
    }
    public int solution(int[][] maps) {
        n=maps.length;
        m=maps[0].length;
        reserved=new boolean[n][];
        for(int i=0;i<n;i++){
            reserved[i]=new boolean[m];
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maps[i][j]==0){
                    reserved[i][j]=true;
                }
            }
        }
        
        Deque<Node> que=new ArrayDeque<>();
        
        Node cur=new Node(0,0,1);
        que.addLast(cur);
        
        ArrayList<Integer> results=new ArrayList();
        
        while(!que.isEmpty()){
            cur=que.pollFirst();
            
            int cy=cur.y;
            int cx=cur.x;
            int cc=cur.c;
            
            if(cy==n-1&&cx==m-1){
                results.add(cc);
                continue;
            }
            
            for(int i=0;i<4;i++){
                int ny=cy+dy[i];
                int nx=cx+dx[i];
                
                if(ny<0||ny>=n) continue;
                if(nx<0||nx>=m) continue;
                
                if(!reserved[ny][nx]){
                    reserved[ny][nx]=true;
                    que.addLast(new Node(ny,nx,cc+1));
                }
            }
        }
        
        int answer = 0;
        
        if(results.isEmpty()){
            return -1;
        }
        
        Collections.sort(results);
        
        answer=results.get(0);
        
        return answer;
    }
}