import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        Set<Integer> s=new HashSet<>();
        for(int n:nums){
            s.add(n);
        }
        
        int ns=nums.length/2;
        int ss=s.size();
        if(ss>=ns){
            answer=ns;
        }
        else{
            answer=ss;
        }
        return answer;
    }
}