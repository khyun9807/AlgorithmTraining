import java.util.*;

class Solution {
    int nlen=0;
    int mlen=0;
    int answer=0;
    int[][]map=null;
    ArrayDeque<int[]> que=new ArrayDeque<>();
    //y,x,v
    
    int[]dy=new int[]{-1,0,1,0};
    int[]dx=new int[]{0,1,0,-1};
    
    ArrayDeque<Integer> results=new ArrayDeque<>();
    
    void func(){
        int cy=0;int cx=0;int cv=1;
        que.addLast(new int[]{cy,cx,cv});
        map[cy][cx]=0;
        while(!que.isEmpty()){
            int[] c=que.peekFirst();
            que.removeFirst();
            cy=c[0];cx=c[1];cv=c[2];
            if(cy==nlen-1&&cx==mlen-1){
                results.addLast(cv);
                continue;
            }
            
            for(int i=0;i<4;i++){
                int ny=cy+dy[i];
                if(ny<0||ny>=nlen)continue;
                int nx=cx+dx[i];
                if(nx<0||nx>=mlen)continue;
                
                if(map[ny][nx]==0)continue;
                
                int nv=cv+1;
                
                que.addLast(new int[]{ny,nx,nv});
                map[ny][nx]=0;
            }
        }
    }
    
    public int solution(int[][] maps) {
        nlen=maps.length;
        mlen=maps[0].length;
        map=new int[nlen][];
        for(int i=0;i<nlen;i++){
            map[i]=Arrays.copyOf(maps[i],mlen);
        }
        
        func();
        
        if(results.isEmpty()) return -1;
        
        answer=Collections.min(results);
        
        return answer;
    }
}