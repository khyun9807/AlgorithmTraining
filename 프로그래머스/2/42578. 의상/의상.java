import java.util.*;
class Solution {
    public int solution(String[][] clothes) {
        int answer = 0;
        
        int olen=clothes.length;
        Map<String,HashSet<String>> m=new HashMap<>();
        
        for(String[] clothe:clothes){
            HashSet<String> s=m.getOrDefault(clothe[1],new HashSet<String>());
            s.add(clothe[0]);
            m.put(clothe[1],s);
        }
        
        Set<String> keySet=m.keySet();
        int mul=1;
        for(String key : keySet){
            int cnt=m.get(key).size();
            ++cnt;
            mul*=cnt;
        }
        
        answer=mul-1;
        return answer;
    }
}