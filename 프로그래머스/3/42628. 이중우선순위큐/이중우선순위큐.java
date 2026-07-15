import java.util.*;

class Solution {
    PriorityQueue<Integer> maxpq=new PriorityQueue<>(Collections.reverseOrder());
    PriorityQueue<Integer> minpq=new PriorityQueue<>();
    
    public int[] solution(String[] operations) {
        int[] answer = {0,0};
        
        for(String op:operations){
            String[] s=op.split(" ");
            int x=Integer.parseInt(s[1]);
            
            if(s[0].equals("I")){
                maxpq.add(x);
                minpq.add(x);
            }
            else{
                if(x==1){
                    Integer y=maxpq.poll();
                    if(y!=null){
                        minpq.remove(y);
                    }
                }
                else{
                    Integer y=minpq.poll();
                    if(y!=null){
                        maxpq.remove(y);
                    }
                }
            }
        }
        
        if(!maxpq.isEmpty()){
            answer[0]=maxpq.peek();
        }
        
        if(!minpq.isEmpty()){
            answer[1]=minpq.peek();
        }
        
        return answer;
    }
}