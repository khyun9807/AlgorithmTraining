import java.util.*;

class Solution {
    int nlen=0;
    int answer=0;
    
    int[] getParent=null;
    
    void union(int a,int b){
        int ra=findRoot(a);
        int rb=findRoot(b);
        
        if(ra==rb) return;
        
        getParent[b]=ra;
        getParent[rb]=ra;
    }
    
    int findRoot(int a){
        int pa=getParent[a];
        if(pa==a) return a;
        
        int ra=findRoot(pa);
        getParent[a]=ra;
        return ra;
    }
    
    public int solution(int n, int[][] computers) {
        nlen=n;
        getParent=new int[nlen];
        for(int i=0;i<nlen;i++){
            getParent[i]=i;
        }
        
        for(int i=0;i<nlen;i++){
            for(int j=i+1;j<nlen;j++){
                if(i==j)continue;
                if(computers[i][j]==1){
                    union(i,j);
                }
            }
        }
        
        for(int i=0;i<nlen;i++){
            if(i==getParent[i])++answer;
        }
        return answer;
    }
}