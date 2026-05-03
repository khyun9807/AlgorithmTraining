#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(auto& scv : scoville){
        pq.push(scv);
    }
    
    int count=0;
    while(!pq.empty()&&pq.top()<K){
        int fst=pq.top();
        pq.pop();
        
        if(pq.empty()){
            return -1;
        }
        
        int scd=pq.top();
        pq.pop();
        
        int newv=fst+(scd*2);
        
        pq.push(newv);
        
        ++count;
    }
    
    
    answer=count;
    return answer;
}