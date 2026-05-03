#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int plen=progresses.size();
    int curprogress=0;
    while(1){
        if(curprogress>=plen){
            break;
        }
        
        for(int i=curprogress;i<plen;i++){
            int& progress=progresses.at(i);
            int speed=speeds.at(i);
            
            progress+=speed;
        }
        
        if(progresses.at(curprogress)>=100){
            int count=0;
            for(int i=curprogress;i<plen;i++){
                int progress=progresses.at(i);
                if(progress>=100){
                    count++;
                }
                else{
                    break;
                }                
            }
            answer.push_back(count);
            curprogress+=count;
        }
    }
    
    return answer;
}