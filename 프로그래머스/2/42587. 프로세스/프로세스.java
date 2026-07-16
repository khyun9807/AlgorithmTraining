import java.util.*;

class Solution {
    public class Node{
        public int pri;
        public int id;
        public Node(int _pri,int _id){
            pri=_pri;
            id=_id;
        }
    }
    public int solution(int[] priorities, int location) {
        int answer = 0;
        int len=priorities.length;
        Deque<Node> dq=new ArrayDeque<>();
        PriorityQueue<Node> pq=new PriorityQueue<>((a,b)->b.pri-a.pri);
        for(int i=0;i<len;i++){
            dq.addLast(new Node(priorities[i],i));
            pq.add(new Node(priorities[i],i));
        }
        
        List<Integer> li=new ArrayList<>();
        while(!pq.isEmpty()){
            Node mx=pq.peek();
            
            while(mx.pri!=dq.peekFirst().pri){
                dq.addLast(dq.pollFirst());
            }
            
            int ot=dq.pollFirst().id;
            pq.poll();
            
            li.add(ot);
        }
        
        
        for(int i=0;i<li.size();i++){
            if(location==li.get(i)){
                answer=i+1;
            }
            System.out.println(li.get(i));
        }
        
        return answer;
    }
}