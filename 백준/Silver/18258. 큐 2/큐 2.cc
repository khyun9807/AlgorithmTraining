#include <iostream>
using namespace std;



class Q {
public:
    int arr[2000000] = { 0, };
    int size = 0;
    int fi = -1;
    int bi = -1;

    void push(int rg) {
        ++size;
        arr[++bi] = rg;
    }

    int pop() {
        if (size <= 0)
            return -1;

        --size;
        return arr[++fi];
    }

    int empty() {
        return size <= 0 ? 1 : 0;
    }

    int front() {
        if (size <= 0)
            return -1;

        return arr[fi + 1];
    }

    int back() {
        if (size <= 0)
            return -1;

        return arr[bi];
    }
};


Q q;
int DO(string str) {
    if (str == "pop") {
        return q.pop();
    }
    else if (str == "size") {
        return q.size;
    }
    else if (str == "empty") {
        return q.empty();
    }
    else if (str == "front") {
        return q.front();
    }
    else if (str == "back") {
        return q.back();
    }
    else
        return -1;
}

int cm;
string cmd;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> cm;

    for (int i = 0; i < cm; i++) {
        cin >> cmd; 
        if (cmd == "push") {
            int arg;
            cin >> arg;
            q.push(arg);
        }
        else
            cout << DO(cmd) << "\n";
    }

    return 0;
}