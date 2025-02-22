#include <iostream>
#include <deque>

using namespace std;

int n, m;
bool** matrix;

void parse(int& f, string& str) {
	int idx = 0;
	for (char c : str) {
		if (c == '0')matrix[f][idx] = false;
		else matrix[f][idx] = true;

		++idx;
	}
}

void init() {
	cin >> n >> m;

	matrix = new bool* [n];
	for (int i = 0; i <= n - 1; i++) {
		matrix[i] = new bool[m];
	}

	for (int i = 0; i <= n - 1; i++) {
		string str;
		cin >> str;
		parse(i, str);
	}
}

enum dir {
	up,right,down,left
};
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

struct info {
	char x;
	char y;
	short w;
};

bool valid(info& _info, int& y, int& x) {
	if (_info.y + y < 0) {
		return false;
	}
	if (_info.y + y >= n) {
		return false;
	}
	if (_info.x + x < 0) {
		return false;
	}
	if (_info.x + x >= m) {
		return false;
	}

	return matrix[_info.y + y][_info.x + x];
}

info bfs() {
	deque<info> que;

	info cur = { 0,0,1 };
	matrix[cur.y][cur.x] = false;

	que.push_back(cur);

	while (1) {
		cur = que.front();
		que.pop_front();

		if (cur.x == m-1 && cur.y == n-1) {
			//
			return cur;
		}

		for (int i = 0; i <= 3; i++) {
			if (valid(cur, dy[i], dx[i])) {
				matrix[cur.y + dy[i]][cur.x + dx[i]] = false;
				que.push_back({ (char)(cur.x + dx[i]),(char)(cur.y + dy[i]),(short)(cur.w + 1) });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	info _info = bfs();

	cout << _info.w;
	return 0;
}