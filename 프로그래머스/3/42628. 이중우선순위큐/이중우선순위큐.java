import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        PriorityQueue<Integer> pqmax=new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> pqmin=new PriorityQueue<>();
        
        Map<Integer,Integer> livemap=new HashMap<>();
        
        for(String op:operations){
            char c=op.charAt(0);
            int num=Integer.parseInt(op.substring(2));
            
            if(c=='I'){
                pqmax.add(num);
                pqmin.add(num);
                int val=livemap.getOrDefault(num,0);
                livemap.put(num,val+1);
            }
            else{
                if(num==1){//remove max
                    while(!pqmax.isEmpty()){
                        int cur=pqmax.poll();
                        int val=livemap.get(cur);
                        if(val<=0){
                            continue;
                        }
                        else{
                            livemap.replace(cur,val-1);
                            break;
                        }
                    }
                }
                else{//rmv min
                    while(!pqmin.isEmpty()){
                        int cur=pqmin.poll();
                        int val=livemap.get(cur);
                        if(val<=0){
                            continue;
                        }
                        else{
                            livemap.replace(cur,val-1);
                            break;
                        }
                    }
                }
            }
        }
        
        int mx=0;
        int mn=0;
        
        while(!pqmax.isEmpty()){
            int cur=pqmax.poll();
            int val=livemap.get(cur);
            if(val<=0){
                continue;
            }
            else{
                mx=cur;
                break;
            }
        }
        while(!pqmin.isEmpty()){
            int cur=pqmin.poll();
            int val=livemap.get(cur);
            if(val<=0){
                continue;
            }
            else{
                mn=cur;
                break;
            }
        }
        
        answer[0]=mx;
        answer[1]=mn;
        
        return answer;
    }
}