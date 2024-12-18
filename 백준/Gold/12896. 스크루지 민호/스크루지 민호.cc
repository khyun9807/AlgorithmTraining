#include <iostream>

//memory
//2^9 X 2^20 = 1024 1024 512
//10,000,000,000

//트리에서 경로 관련된 문제는
//항상 거리가 가장 먼 노드간의 루트를 주목!

#include <unordered_map>
#include <deque>

using namespace std;

int inputN;
unordered_map<int, deque<int>> matrix;

pair<int,int> getFarNodeNDist(int s) {
	deque<bool> visited(inputN+1, false);
	
	deque<pair<int, int>> bfs;//node acculweight

	bfs.push_back(pair<int,int>(s,0));
	
	int maxN = s;
	int maxL = 0;
	

	while (!bfs.empty()) {
		int curnode = bfs.front().first;
		int acculw = bfs.front().second;

		bfs.pop_front();

		visited[curnode] = true;

		if (maxL < acculw) {
			maxL = acculw;
			maxN = curnode;
		}

		int len = matrix[curnode].size();
		for (int i = 0; i <= len - 1; i++) {
			int neighborNode = matrix[curnode][i];
			if (!visited[neighborNode]) {
				bfs.push_back(pair<int, int>(neighborNode, acculw + 1));
			}
		}

	}


	return pair<int, int>(maxN, maxL);
}

void input() {

	cin >> inputN;

	for (int i = 0; i <= inputN - 2; i++) {
		int s, d;
		cin >> s >> d;

		//matrix[s].push_back(d);
		//matrix[d].push_back(s);

		//matrix.insert({ s,{d} });
		//matrix.insert({ d,{s} });

		matrix.insert(pair<int, deque<int>>(s, deque<int>()));
		matrix[s].push_back(d);
		matrix.insert(pair<int, deque<int>>(d, deque<int>()));
		matrix[d].push_back(s);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();


	pair<int,int> A = getFarNodeNDist(1);

	pair<int, int> B = getFarNodeNDist(A.first);
	
	cout << (B.second+1)/2;

	return 0;
}