#include <string>
#include <vector>
#include <deque>
#include <queue>

#include <iostream>

using namespace std;

class node {
public:
    int num;
    int req;
    int dur;
    node(int num, int req, int dur) :num(num), req(req), dur(dur) {}

    bool operator==(const node& right)const {
        return num == right.num && (req == right.req && dur == right.dur);
    }

    bool operator!=(const node& right)const {
        return !((*this) == right);
    }

    bool operator<(const node& right)const {
        if (dur != right.dur) return dur > right.dur;

        if (req != right.req) return req > right.req;

        return num > right.num;
    }

    bool operator>=(const node& right)const {
        return !((*this) < right);
    }

    bool operator>(const node& right)const {
        return right < (*this);
    }

    bool operator<=(const node& right)const {
        return !((*this) > right);
    }
};

priority_queue<node, deque<node>> pq;

deque<int> record;

int solution(vector<vector<int>> jobs2) {//번호, 요청시각, 소요시간 //소요> 요청> 번호
    deque<deque<int>> jobs;
    
    
    int answer = 0;

    int jlen = jobs2.size();
    for (int i = 0; i < jlen; i++) {
        vector<int>& job = jobs2.at(i);
        jobs.push_back({i,job.at(0),job.at(1)});
        
        //pq.push(node(i, job.at(0), job.at(1)));
    }

    int count = 0;

    while (true) {
        if(!jobs.empty()){
            int jlen=jobs.size();
            for(int i=0;i<jlen;i++){
                deque<int> ji=jobs.front();
        
                if(ji.at(1)<=count){
                    pq.push(node(ji.at(0),ji.at(1),ji.at(2)));
                    jobs.pop_front();
                }
                else{
                    jobs.push_back(ji);
                    jobs.pop_front();
                }
            }   
        }
        else if(pq.empty()){
            break;
        }
        
        if(pq.empty()){
            ++count;
            continue;
        }
        
        node cur = pq.top();

        if (count < cur.req) {
            count = cur.req;
            continue;
        }

        pq.pop();
        cout<<cur.num;

        count += cur.dur;
        int res = count - cur.req;

        record.push_back(res);
    }

    int sum = 0;
    int rs = record.size();
    for (int i = 0; i < rs; i++) {
        sum += record.at(i);
    }

    answer = sum / rs;
    return answer;
}