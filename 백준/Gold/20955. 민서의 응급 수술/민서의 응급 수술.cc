
//20955번 다시 풀기 민서
// 
//4315번 다시 풀기 구슬 옮기기
//트리 문제 그래프 말고 트리로 바라보며 다시 풀어보기.
//=> ㄴㄴ 그래프로 풀 수 있음

//2960번 다시풀기
//22943번 다시풀기

#include <iostream>
#include <unordered_map>
#include <deque>
#include <set>

using namespace std;

unordered_map<int, deque<int>> matrix;
deque<bool> visited;

int N;
int M;

void input() {
	cin >>N>>M;

	visited.assign(N + 1, false);

	for (int i = 1; i <= N; i++) {
		matrix.insert({});
	}

	for (int i = 1; i <= M; i++) {
		int s, d;
		cin >> s >> d;

		matrix[s].push_back(d);
		matrix[d].push_back(s);
	}
}



void bfs(int s) {
	deque<int> reserved;
	reserved.push_back(s);

	while (!reserved.empty()) {
		int cn = reserved.front();
		reserved.pop_front();

		visited[cn] = true;

		int nc = matrix[cn].size();
		for (int i = 0; i <= nc - 1; i++) {
			int nn = matrix[cn][i];

			if (!visited[nn]) {
				reserved.push_back(nn);
			}
		}

	}
}
int GetBundleCount() {
	int result = 0;


	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			++result;
			bfs(i);
		}
	}

	return result;
}

/*
int GetWholeEdgeCount() {
	unordered_map<int, set<int>> temp;

	for (int i = 1; i <= N; i++) {
		temp[i].insert(matrix[i].begin(), matrix[i].end());
	}

	int result = 0;

	for (int i = 1; i <= N; i++) {
		int cn = i;

		while (!temp[cn].empty()) {
			int nn=*(temp[cn].begin());

			temp[cn].erase(temp[cn].begin());
			temp[nn].erase(cn);

			++result;
		}
	}


	return result;
}
*/


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	int bc = GetBundleCount();

	int result = (bc - 1) + (bc - 1 + M - (N - 1));

	cout << result;

	return 0;
}