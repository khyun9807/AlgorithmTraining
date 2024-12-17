#include <iostream>
#include <deque>
#include <unordered_map>

using namespace std;



struct edge {
	int node;
	int w;
};

unordered_map<int, deque<edge>> graph;
int N;
pair<int, int> findFarNode(int s) {
	deque<bool> visited(N+1, false);

	int max = 0;
	int resultnode = 0;


	deque<edge> bfs;
	bfs.push_back({ s,0 });
	

	while (!bfs.empty()) {
		int node = bfs.front().node;
		int w = bfs.front().w;
		bfs.pop_front();
		visited[node] = true;

		int len = graph[node].size();

		bool isAllVisit = true;
			for (int i = 0; i <= len - 1; i++) {
				if (!visited[graph[node][i].node]) {
					bfs.push_back({ graph[node][i].node,
					w + graph[node][i].w });
					isAllVisit = false;
				}
			}

			if (isAllVisit) {
				if (max < w) {//max가 같은 값이 여러개인 경우는?
					max = w;
					resultnode = node;
				}
			}

	}

	return pair<int, int>(max, resultnode);
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);



	cin >> N;
	for (int i = 0; i <= N - 2; i++) {
		int s, d, w; cin >> s >> d >> w;

		graph[s].push_back({ d,w });
		graph[d].push_back({ s,w });
	}


	pair<int,int> p = findFarNode(1);
	int fn = p.second;


	pair<int, int> f = findFarNode(fn);

	cout << f.first;

	return 0;
}