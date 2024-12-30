

//4315번 다시 풀기 구슬 옮기기
//트리 문제 그래프 말고 트리로 바라보며 다시 풀어보기.
//=> ㄴㄴ 그래프로 풀 수 있음


//22943번 다시풀기
//22942번
//3343번 다시풀기

#include <iostream>
#include <deque>
#include <set>
#include <unordered_map>

using namespace std;

int n;
deque<int> marbles;
deque<int> edges;
deque<int> reserved;

unordered_map<int, set<int>> matrix;

void input() {
	reserved.clear();
	marbles.clear();
	edges.clear();
	matrix.clear();

	marbles.assign(n + 1, 0);
	edges.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		reserved.push_back(i);

		int t; cin >> t;

		cin >> marbles[i];

		cin >> t;
		for (int j = 1; j <= t; j++) {
			int q; cin >> q;

			matrix[i].insert(q);
			matrix[q].insert(i);

			++edges[i];
			++edges[q];
		}
	}
}

long long solution() {
	long long result = 0;

	while (!reserved.empty()) {
		int curnode = reserved.front();
		reserved.pop_front();

		if (edges[curnode] > 1) {
			reserved.push_back(curnode);
			continue;
		}
		else if (edges[curnode] == 0)
			break;

		//말단 노드 확정 혹은 점

		int marbleCount = marbles[curnode];

		int neighbornode = *(matrix[curnode].begin());

		if (marbleCount == 1) {
			//none
		}
		else if (marbleCount < 1) {
			marbles[curnode] += (1 - marbleCount);
			marbles[neighbornode] -= (1 - marbleCount);

			result += (1-marbleCount);
		}
		else {//marbleCount>1
			marbles[curnode] -= (marbleCount - 1);
			marbles[neighbornode] += (marbleCount - 1);

			result += (marbleCount-1);
		}

		//concern time
		matrix[curnode].erase(matrix[curnode].begin());
		matrix[neighbornode].erase(curnode);

		--edges[curnode];
		--edges[neighbornode];
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> n;

		if (n == 0)
			break;

		input();

		cout<<solution()<<"\n";
	}

	return 0;
}