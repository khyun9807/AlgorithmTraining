import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        int[] answer = {};
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("Hello Java");
        
        Deque<Integer> dq=new ArrayDeque<>();
        
        for(int x:arr){
            if(dq.isEmpty()){
                dq.addLast(x);
            }
            else{
                int l=dq.peekLast();
                if(l!=x){
                    dq.addLast(x);
                }
            }
        }
        
        int dql=dq.size();
        answer=new int[dql];
        for(int i=0;i<dql;i++){
            answer[i]=dq.pollFirst();
        }
        
        return answer;
    }
}