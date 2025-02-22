#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

struct node {
	deque<int> neighbors;
};

deque<node> matrix;
int s;
int n, m;


string result1;
string result2;

void bfs() {
	int start = s;
	deque<bool> visited(n + 1, false);
	deque<int> que;


	deque<bool> mentioned(n + 1, false);

	que.push_back(start);
	if (!mentioned.at(start)) {
		result2 += (to_string(start) + " ");
		mentioned.at(start) = true;
	}

	while (!que.empty()) {
		int cur = que.front();

		

		que.pop_front();

		visited.at(cur) = true;

		deque<int>& neighbors=matrix.at(cur).neighbors;

		for (int neighbor : neighbors) {
			if (!visited.at(neighbor)) {
				que.push_back(neighbor);

				if (!mentioned.at(neighbor)) {
					result2 += (to_string(neighbor) + " ");
					mentioned.at(neighbor) = true;
				}
			}
		}

	}
}

void dfs() {
	int start = s;
	deque<int> stck;
	deque<bool> completed(n+1,false);
	deque<bool> tracked(n + 1, false);

	deque<bool> mentioned(n + 1, false);

	
	stck.push_back(start);
	tracked.at(start) = true;

	while (!completed.at(start)) {
		int cur = stck.back();
		if (!mentioned.at(cur)) {
			result1 += (to_string(cur) + " ");
			mentioned.at(cur) = true;
		}

		deque<int>& neighbors = matrix.at(cur).neighbors;

		bool goBack = true;
		for (int neighbor : neighbors) {
			if (!tracked.at(neighbor) && !completed.at(neighbor)) {
				stck.push_back(neighbor);
				tracked.at(neighbor) = true;

				goBack = false;
				break;
			}
		}

		if (goBack) {
			completed.at(cur) = true;

			stck.pop_back();
			tracked.at(cur) = false;
		}
	}
}

int main() {

	//200,000,000연산
	//12*1024*1024바이트

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> s;
	matrix.assign(n + 1, {});

	for (int i = 1; i <= m; i++) {
		int x, q;
		cin >> x >> q;

		if (x == q)
			continue;

		matrix.at(x).neighbors.push_back(q);
		matrix.at(q).neighbors.push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		sort(matrix.at(i).neighbors.begin(), matrix.at(i).neighbors.end());
		unique(matrix.at(i).neighbors.begin(), matrix.at(i).neighbors.end());
	}

	dfs();
	bfs();

	cout << result1 <<"\n"<<result2;
	return 0;
}