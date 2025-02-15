#include <iostream>

#include <deque>



using namespace std;

deque<deque<int>> matrix;




deque<bool> visited;

int recursivedfs(int s) {
	visited.at(s) = true;

	int len = matrix.at(s).size() - 1;

	int max = 1;

	bool isEnd = true;
	for (int i = 0; i <= len; i++) {
		int n = matrix.at(s).at(i);
		if (visited.at(n) == false) {
			isEnd = false;
			int r=recursivedfs(n);
			if (r > max)
				max = r;

			if (max >= 5)
				return 5;
		}
	}

	visited.at(s) = false;
	if (isEnd)
		return 1;
	else
		return max + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);



	int n, m;
	cin >> n >> m;

	visited.assign(n+1, false);
	matrix.assign(n + 1, {});

	while (m-- > 0) {
		int s, e;
		cin >> s >> e;

		matrix.at(s).push_back(e);
		matrix.at(e).push_back(s);
	}

	for (int i = 1; i <= n; i++) {

		int r = recursivedfs(i);

		if (r >= 5) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;

	return 0;
}