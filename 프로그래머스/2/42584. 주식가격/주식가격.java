import java.util.*;
class Solution {
    public class Node{
        public int price;
        public int time;
        public Node(int _price,int _time){
            price=_price;
            time=_time;
        }
    }
    public int[] solution(int[] prices) {
        int[] answer = {};
        
        int len=prices.length;
        
        //int [][]m=new int[len][len];
        answer =new int[len];
        
        for(int i=0;i<len;i++){
            int count=0;
            for(int j=i+1;j<len;j++){
                ++count;
                if(prices[j]-prices[i]<0){
                    break;
                }
            }
            answer[i]=count;
        }
        
        
        return answer;
    }
}