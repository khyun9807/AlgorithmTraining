#include<iostream>
#include<list>
#include<deque>

using namespace std;

list<int> lt;
deque<int> result;


int N, K;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    
    for (int i = 0; i < N; i++) {
        lt.push_back(i + 1);
    }


    list<int>::iterator liter = lt.begin();
    while (!lt.empty()) {
        for (int i = 0; i < K - 1; i++) {
            
            liter++;
            if (liter == lt.end())
                liter = lt.begin();
        }

        int temp = *liter;


        liter++;
        if (liter == lt.end())
            liter = lt.begin();
        
        lt.remove(temp);

        result.push_back(temp);
    }



    cout << "<";

    int lng = result.size();
    for (int i = 0; i <= lng - 2; i++)
        cout << result[i] << ", ";

    cout << result[lng - 1];
    cout << ">";
    return 0;
}