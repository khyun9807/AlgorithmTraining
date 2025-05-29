#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    deque<deque<bool>> adjm(n + 1);

    for (int i = 1; i <= n; i++) {
        deque<bool> dq(n + 1, false);
        adjm.at(i) = dq;
    }
    /////////////////////////
    int wlen = wires.size();
    for (int i = 0; i < wlen; i++) {
        int a = wires.at(i).at(0);
        int b = wires.at(i).at(1);

        adjm.at(a).at(b) = true;
        adjm.at(b).at(a) = true;
    }
    ////////////////////////////////////

    int result = 101;

    for (int i = 0; i < wlen; i++) {
        int a = wires.at(i).at(0);
        int b = wires.at(i).at(1);

        adjm.at(a).at(b) = false;
        adjm.at(b).at(a) = false;

        //dfs start

        deque<int> tracker;
        deque<bool> tracked(n + 1, false);
        deque<bool> completed(n + 1, false);
        deque<bool> counted(n + 1, false);
        int count = 0;

        int cur = a;

        tracker.push_back(cur);
        tracked.at(cur) = true;

        while (true) {
            if (!counted.at(cur)) {
                counted.at(cur) = true;
                ++count;
            }

            bool isCompleted = true;

            for (int j = 1; j <= n; j++) {
                bool isneighbor = adjm.at(cur).at(j);

                if (isneighbor) {

                    if (!tracked.at(j) && !completed.at(j)) {
                        tracker.push_back(j);
                        tracked.at(j) = true;

                        isCompleted = false;
                        break;
                    }
                }
            }

            if (isCompleted) {
                tracker.pop_back();
                tracked.at(cur) = false;
                completed.at(cur) = true;

                if (tracker.empty())
                    break;
                else
                    cur = tracker.back();
            }
            else {
                cur = tracker.back();
            }
        }

        int temp = n - (2 * count);
        temp = temp >= 0 ? temp : -temp;
        if (result > temp)
            result = temp;
        //dfs end

        adjm.at(a).at(b) = true;
        adjm.at(b).at(a) = true;
    }


    return result;
}