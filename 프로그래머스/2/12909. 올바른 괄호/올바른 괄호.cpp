#include<string>
#include <deque>
#include <iostream>

using namespace std;

deque<char> st;

bool solution(string s)
{
    bool answer = true;

    int len=s.length();
    
    for(int i=0;i<len;i++){
        char& c=s.at(i);
        
        if(c=='('){
            st.push_back(c);
        }
        else if(c==')'){
            if(st.empty()){
                answer=false;
                break;
            }
            else{
                if(st.back()=='('){
                    st.pop_back();
                }
                else{
                    answer=false;
                    break;
                }
            }
        }
        else{
            answer=false;
            break;
        }
    }
    
    if(!st.empty()){
        answer=false;
    }

    return answer;
}