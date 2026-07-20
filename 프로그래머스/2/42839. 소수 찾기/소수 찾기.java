import java.util.*;

class Solution {
    boolean[] visited;
    Set<Integer> sett;
    int len;
    
    boolean isSosu(int num){
        if(num==0){
            return false;
        }
        else if(num==1){
            return false;
        }
        int cnt=0;
        for(int i=2;i<=num/2;i++){
            if(num%i==0){
                return false;
            }
        }
        
        return true;
    }
    
    void dfs(int[] nums,int count,int num){
        sett.add(num);
        for(int i=0;i<len;i++){
            if(!visited[i]){
                visited[i]=true;
                int temp=num*10+nums[i];
                dfs(nums,count+1,temp);
                visited[i]=false;
            }
        }
    }
    
    public int solution(String numbers) {
        len=numbers.length();
        visited=new boolean[len];
        
        int[] nums=new int[len];
        for(int i=0;i<len;i++){
            nums[i]=Integer.parseInt(numbers.charAt(i)+"");
        }
        
        sett=new HashSet<>();
        dfs(nums,0,0);
        
        int result=0;
        for(int x : sett){
            //System.out.println(x);
            if(isSosu(x)){
                ++result;
            }
        }
        //System.out.println(isSosu(4));
        int answer = result;
        return answer;
    }
}