import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        int len=citations.length;
        Arrays.sort(citations);
        
        int mxx=citations[citations.length-1];
        int mx=0;
        for(int i=0;i<=mxx;i++){
            int count=0;
            for(int j=0;j<len;j++){
                if(citations[j]>=i){
                    ++count;
                }
            }
            if(count>=i){
                if(mx<i){
                    mx=i;
                }
            }
        }
        answer=mx;
        return answer;
    }
}