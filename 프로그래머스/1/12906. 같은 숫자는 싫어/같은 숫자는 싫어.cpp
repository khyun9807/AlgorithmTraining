#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int len=arr.size();
    
    int st=arr.at(0);
    answer.push_back(st);
    for(int i=1;i<len;i++){
        int cur=arr.at(i);
        if(st!=cur){
            answer.push_back(cur);
        }
        st=cur;
    }

    return answer;
}