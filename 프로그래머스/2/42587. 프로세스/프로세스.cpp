#include <string>
#include <vector>
#include <deque>

using namespace std;

// ABCD
// 2132 //클수록 높음

// ABCD -> CDAB 

// CDAB

class node{
    public:
    int idx;
    int pri;
    node(int idx, int pri):idx(idx),pri(pri){}
};

int getIdxWithMax(deque<node>& inf){
    node max=node(0,inf.at(0).pri);
    
    int len=inf.size();
    for(int i=0;i<len;i++){
        node cur=inf.at(i);
        
        if(cur.pri>max.pri){
            max=node(i,cur.pri);
        }
    }
    
    return max.idx;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    deque<node> inf;
    
    int plen = priorities.size();
    for(int i=0;i<plen;i++){
        inf.push_back(node(i,priorities.at(i)));
    }
    
    int count=0;
    while(!inf.empty()){
        node cur=inf.front();
        
        node& max=inf.at(getIdxWithMax(inf));
        
        if(cur.pri==max.pri){
            inf.pop_front();
            ++count;
            if(cur.idx==location){
                answer=count;
                break;
            }
        }
        else{
            inf.pop_front();
            inf.push_back(cur);
        }
    }
    
    return answer;
}