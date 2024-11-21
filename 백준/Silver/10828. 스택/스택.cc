#include <iostream>

#include <stack>

using namespace std;

stack<int> s;

int cm;
string cmd;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);;
    cin>>cm;
    
    while(cm-->0){
        cin>>cmd;
        
        if(cmd=="push"){
            int arg;
            cin>>arg;
            s.push(arg);
        }
        else if(cmd=="pop"){
            if(s.empty())
                cout<<-1<<"\n";
            else{
                cout<<s.top()<<"\n";
                s.pop();
            }
        }
        else if(cmd=="size"){
            cout<<s.size()<<"\n";
        }
        else if(cmd=="empty"){
            if(s.empty())
                cout<<1<<"\n";
            else
                cout<<0<<"\n";
        }
        else if(cmd=="top"){
            if(s.empty())
                cout<<-1<<"\n";
            else
                cout<<s.top()<<"\n";
        }
    }
    
    return 0;
}