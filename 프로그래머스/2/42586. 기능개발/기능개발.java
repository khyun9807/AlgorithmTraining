import java.util.*;
class Solution {
    public class Node{
        public int cur;
        public int speed;
        
        public Node(int _cur, int _speed){
            cur=_cur; speed=_speed;
        }
    }
    
    public int[] solution(int[] progresses, int[] speeds) {
        int len=progresses.length;
        int[] answer = {};
        
        Deque<Node> dq=new ArrayDeque<>();
        for(int i=0;i<len;i++){
            Node n=new Node(progresses[i],speeds[i]);
            dq.addLast(n);
        }
        
        List<Integer> result=new ArrayList<>();
        
        while(!dq.isEmpty()){
            
            
            int dlen=dq.size();
            for(int i=0;i<dlen;i++){
                Node cur=dq.pollFirst();
                cur.cur+=cur.speed;
                dq.addLast(cur);
            }
            
            int count=0;
            while(!dq.isEmpty()){
                if(dq.peekFirst().cur>=100){
                    ++count;
                    dq.pollFirst();
                }
                else{
                    break;
                }
            }
            
            if(count>=1){
                result.add(count);
            }
        }
        
        int rlen=result.size();
        answer=new int[rlen];
        for(int i=0;i<rlen;i++){
            answer[i]=result.get(i);
        }
        
        return answer;
    }
}