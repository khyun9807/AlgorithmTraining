#include <string>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

class node {
public:
    int cost;
    int s;
    int d;
    node(int cost, int s, int d) :cost(cost), s(s), d(d) {}

    bool operator<(const node& n)const {
        return cost > n.cost;
    }
};

priority_queue<node> pq;
deque<int> parent;

int findparent(int c) {
    if (c == parent.at(c)) {
        return c;
    }

    parent.at(c) = findparent(parent.at(c));
    return parent.at(c);
}

void unionparent(int a, int b) {
    a = findparent(a);
    b = findparent(b);

    if (a < b) {
        parent.at(b) = a;
    }
    else {
        parent.at(a) = b;
    }
}

bool issamegroup(int a, int b) {
    return findparent(a) == findparent(b);
}

int solution(int n, vector<vector<int>> costs) {
    parent.assign(n, 0);
    for (int i = 0; i < n; i++) {
        parent.at(i) = i;
    }

    int answer = 0;

    for (vector<int>& cost : costs) {
        pq.push(node(cost.at(2),cost.at(0), cost.at(1)));
    }


    int count = 0;
    while (!pq.empty()) {
        node cur = pq.top();
        pq.pop();

        if (!issamegroup(cur.s, cur.d)) {
            ++count;
            answer += cur.cost;
            unionparent(cur.s, cur.d);
        }

        if (count == n - 1)
            break;
    }

    return answer;
}