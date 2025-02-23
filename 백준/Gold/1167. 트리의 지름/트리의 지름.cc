#include <iostream>
#include <deque>
#include <string>
using namespace std;

struct neighbor {
	int n;
	int w;
};

deque<deque<neighbor>> matrix;

int n;

void parse(string& str) {
	int len = str.length() - 1;
	int s;

	int num = 0;
	int we = 0;
	bool ready = false;
	for (int i = 0; i <= len; i++) {
		if (i == 0) {
			s = str[i]-'0';
			++i;
			continue;
		}
		else {
			char& c = str[i];

			switch (c) {
			case '-':
				return;
				break;
			case ' ':
				if (!ready) {
					ready = true;
				}
				else {
					ready = false;
					matrix.at(s).push_back({ num,we });
					num = 0;
					we = 0;
				}

				break;
			default:
				int d = c-'0';

				if (!ready)
					num = num*10+d;
				else
					we = we * 10 + d;

				break;
			}
		}
	}
}

void init() {
	cin >> n;
	cin.ignore();

	matrix.assign(n + 1, {});

	for (int i = 1; i <= n; i++) {

		/*string str;
		getline(cin, str);

		parse(str);
		*/


		int s;
		cin >> s;

		while (1) {
			int x; int w;
			cin >> x;
			if (x == -1)
				break;

			cin >> w;
			matrix.at(s).push_back({ x,w });
		}
	}
}

deque<neighbor> bfs(int s) {
	deque<bool> visited(n + 1, false);
	deque<neighbor> que;

	deque<neighbor> result;
	result.push_back({ 0,0 });

	int start = s;

	que.push_back({start,0});
	visited.at(start) = true;

	while (!que.empty()) {
		neighbor cur=que.front();
		que.pop_front();

		deque<neighbor>& neighbors = matrix.at(cur.n);

		bool deadEnd = true;
		for (neighbor& ni : neighbors) {
			if (!visited.at(ni.n)) {
				deadEnd = false;

				que.push_back({ni.n,cur.w+ni.w});
				visited.at(ni.n) = true;
			}
		}

		if (deadEnd) {
			if (cur.w > result.at(0).w) {
				result.clear();
				result.push_back(cur);
			}
			else if (cur.w == result.at(0).w) {
				result.push_back(cur);
			}
		}
	}

	
	return result;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	deque<neighbor> r1 = bfs(2);

	int max = 0;
	/*for (neighbor& ni : r1) {
		deque<neighbor> r2 = bfs(ni.n);
		if (max < r2.at(0).w)
			max = r2.at(0).w;
	}*/

	max = bfs(r1.at(0).n).at(0).w;

	cout<< max;

	return 0;
}