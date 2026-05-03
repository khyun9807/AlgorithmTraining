#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

deque<int> trucks;
deque<int> bridge;
int weightsum=0;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    trucks.assign(truck_weights.begin(),truck_weights.end());
    
    bridge.assign(bridge_length,0);
    
    int wl=weight;
    
    int count=0;
    while(!trucks.empty()){
        ++count;
        
        int curtruck=trucks.front();
        
        if(weightsum+curtruck-bridge.front()>wl){
            bridge.push_back(0);
        }
        else{
            trucks.pop_front();
            weightsum+=curtruck;
            bridge.push_back(curtruck);
        }
        
        weightsum-=bridge.front();
        bridge.pop_front();
    }
    cout<<count;
    while(weightsum>0){
        ++count;
        
        weightsum-=bridge.front();
        bridge.pop_front();
    }
    
    answer=count;
    
    return answer;
}