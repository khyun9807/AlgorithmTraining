#include <string>
#include <vector>

using namespace std;

// 가운데=>4*3 바깥 =>6*5 바깥타일=> 30-12 18
// 가운데 6 4  바깥 8 6  48-24

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int len=yellow/2+1;
    for(int i=1;i<=len;i++){
        if(yellow%i==0){
            int garo=i;
            int sero=yellow/i;
            if(garo>sero){
                break;
            }
            
            int outgaro=garo+2;
            int outsero=sero+2;
            if(brown==(outgaro*outsero-yellow)){
                answer.push_back(outsero);
                answer.push_back(outgaro);
            }
        }
    }
    
    return answer;
}