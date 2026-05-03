#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int ll=lost.size();
    int rl=reserve.size();
    
    for(int i=0;i<ll;i++){
        lost.at(i)--;
    }
    
    for(int i=0;i<rl;i++){
        reserve.at(i)--;
    }
    
    
    int answer = 0;
    
    vector<int> count;
    count.assign(n,1);
    
    for(int i=0;i<rl;i++){
        count.at(reserve.at(i))++;
    }
    
    for(int i=0;i<ll;i++){
        count.at(lost.at(i))--;
    }
    
    for(int i=0;i<n;i++){
        int c=count.at(i);
        if(c==0){
            if(i-1>=0){
                if(count.at(i-1)>=2){
                    count.at(i-1)--;
                    count.at(i)++;
                    continue;
                }
            }
            
            if(i+1<n){
                if(count.at(i+1)>=2){
                    count.at(i+1)--;
                    count.at(i)++;
                    continue;
                }
            }
            
        }
    }
    
    for(int i=0;i<n;i++){
        if(count.at(i)>=1){
            answer++;
        }
    }
    
    return answer;
}