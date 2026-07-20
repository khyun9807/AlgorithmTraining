import java.util.*;
class Solution {
    class Node{
        public int num;
        public int cnt;
        public Node(int _n,int _c){
            num=_n;
            cnt=_c;
        }
    }
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        ArrayList<String> strs=new ArrayList();
        strs.add(begin);
        int k=-1;
        for(int i=0;i<words.length;i++){
            strs.add(words[i]);
            if(words[i].equals(target)){
                k=i+1;
            }
        }
        if(k==-1){
            return 0;
        }
        
        ArrayList<ArrayList<Integer>> graph=new ArrayList();
        for(int i=0;i<strs.size();i++){
            graph.add(new ArrayList());
        }
        
        for(int i=0;i<strs.size();i++){
            String s=strs.get(i);
            
            for(int j=0;j<strs.size();j++){
                if(i==j)continue;
                
                String e=strs.get(j);
                
                int cnt=0;
                for(int q=0;q<e.length();q++){
                    if(s.charAt(q)!=e.charAt(q)){
                        ++cnt;
                    }
                }
                
                if(cnt==1){
                    graph.get(i).add(j);
                    graph.get(j).add(i);
                }
            }
        }
        
        //0 -> 1
        boolean[] reserved=new boolean[strs.size()];
        reserved[0]=true;
        Deque<Node> que=new ArrayDeque();
        Node cur=new Node(0,0);
        que.addLast(cur);
        
        ArrayList<Integer> records=new ArrayList();
        while(!que.isEmpty()){
            cur=que.pollFirst();
            
            if(cur.num==k){
                records.add(cur.cnt);
                break;
            }
            
            ArrayList<Integer> neighbors=graph.get(cur.num);
            
            for(int neighbor:neighbors){
                if(!reserved[neighbor]){
                    reserved[neighbor]=true;
                    que.addLast(new Node(neighbor,cur.cnt+1));
                }
            }
        }
        
        if(records.isEmpty()){
            return 0;
        }
        
        Collections.sort(records);
        
        answer=records.get(0);
        
        return answer;
    }
}