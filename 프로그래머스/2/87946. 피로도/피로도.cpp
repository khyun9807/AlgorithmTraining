#include <string>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

priority_queue<int> pq;

void backtrack(deque<bool> visited,int count,int piro,vector<vector<int>>& dungeons){
    int dl=visited.size();
    bool isEnd=true;
    for(int i=0;i<dl;i++){
        if(!visited.at(i)&&piro>=dungeons.at(i).at(0)){
            isEnd=false;
            
            visited.at(i)=true;
            backtrack(visited,count+1,piro-dungeons.at(i).at(1),dungeons);
            
            visited.at(i)=false;
        }
    }
    
    if(isEnd){
        pq.push(count);
        return;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    deque<bool> visited;
    visited.assign(dungeons.size(),false);
    
    backtrack(visited,0,k,dungeons);
    
    answer=pq.top();
    return answer;
}