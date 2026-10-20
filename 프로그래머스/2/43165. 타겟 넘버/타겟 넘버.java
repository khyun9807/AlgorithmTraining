import java.util.*;

class Solution {
    int nlen=0;
    int trgt=0;
    int answer=0;
    
    int[] numbers=null;
    
    private void go(int sum,int depth){
        if(depth==nlen){
            if(sum==trgt)++answer;
            return;
        }
        
        go(sum+numbers[depth],depth+1);
        go(sum-numbers[depth],depth+1);
    }
    
    public int solution(int[] numberss, int target) {
        nlen=numberss.length;
        trgt=target;
        numbers=Arrays.copyOf(numberss,nlen);
        
        
        go(0,0);
        
        return answer;
    }
}