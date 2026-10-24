import java.util.*;
class Solution {
    int MIN=Integer.MIN_VALUE;
    int MAX=Integer.MAX_VALUE;
    
    int n=0;
    String cmd[]=null;
    int[][]recordMax=null;
    int[][]recordMin=null;
    
    int getMax(int sidx, int eidx){
        if(sidx==eidx)return recordMax[sidx][eidx]=Integer.parseInt(cmd[sidx]);
        if(recordMax[sidx][eidx]!=MIN)return recordMax[sidx][eidx];
        
        int maxVal=MIN;
        for(int rootOperatorPos=sidx+1;
            rootOperatorPos<=eidx-1;
            rootOperatorPos+=2){
            int newVal=0;
            if("+".equals(cmd[rootOperatorPos]))
                newVal=getMax(sidx,rootOperatorPos-1)+getMax(rootOperatorPos+1,eidx);
            else
                newVal=getMax(sidx,rootOperatorPos-1)-getMin(rootOperatorPos+1,eidx);
            
            maxVal=Math.max(maxVal,newVal);
        }
        recordMax[sidx][eidx]=maxVal;
        
        return maxVal;
    }
    
    int getMin(int sidx, int eidx){
        if(sidx==eidx)return recordMin[sidx][eidx]=Integer.parseInt(cmd[sidx]);
        if(recordMin[sidx][eidx]!=MAX)return recordMin[sidx][eidx];
        
        int minVal=MAX;
        for(int rootOperatorPos=sidx+1;
            rootOperatorPos<=eidx-1;
            rootOperatorPos+=2){
            int newVal=0;
            if("+".equals(cmd[rootOperatorPos]))
                newVal=getMin(sidx,rootOperatorPos-1)+getMin(rootOperatorPos+1,eidx);
            else
                newVal=getMin(sidx,rootOperatorPos-1)-getMax(rootOperatorPos+1,eidx);
            
            minVal=Math.min(minVal,newVal);
        }
        recordMin[sidx][eidx]=minVal;
        
        return minVal;
    }
    
    
    
    public int solution(String arr[]) {
        n=arr.length;
        cmd=new String[n];
        for(int i=0;i<n;i++){
            cmd[i]=arr[i];
        }
        
        recordMax=new int[n][];
        recordMin=new int[n][];
        for(int i=0;i<n;i++){
            recordMax[i]=new int[n];
            Arrays.fill(recordMax[i],MIN);
            recordMin[i]=new int[n];
            Arrays.fill(recordMin[i],MAX);
        }
        
        int answer = getMax(0,n-1);
        return answer;
    }
}