import java.util.*;
class Solution {
    boolean solution(String s) {
        boolean answer = true;

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("Hello Java");
        
        Deque<Character> dq=new ArrayDeque<>();
        char[] str=s.toCharArray();
        for(char c:str){
            if(c=='('){
                dq.addLast(c);
            }
            else{
                if(dq.isEmpty()){
                    return false;
                }
                if(dq.pollLast()!='('){
                    return false;
                }
            }
        }
        
        if(!dq.isEmpty()){
            return false;
        }

        return true;
    }
}