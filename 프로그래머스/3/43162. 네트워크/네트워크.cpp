#include <string>
#include <vector>

using namespace std;

int count=0;

vector<bool> visited;

void dfs(vector<vector<int>>& cs, int s){
    vector<int>& neighbors=cs.at(s);
    visited.at(s)=true;
    
    int len=neighbors.size();
    
    for(int i=0;i<len;i++){
        if(!visited.at(i)&&cs.at(s).at(i)==1){
            dfs(cs,i);
        }
    }
}

int countf(){
    int temp=0;
    int len=visited.size();
    for(int i=0;i<len;i++){
        if(visited.at(i)){
            ++temp;
        }
    }
    
    return temp;
}

int solution(int n, vector<vector<int>> computers) {
    visited.assign(n,false);
    
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(visited.at(i)){
            continue;
        }
        
        int prev=countf();
        dfs(computers,i);
        int next=countf();
        
        if(prev!=next){
            answer++;
        }
    }
    
    return answer;
}