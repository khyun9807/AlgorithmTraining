#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	deque<pair<int,int>> dq;//<height,jmp idx>
	dq.push_back(pair<int,int>(100000001,0));

	int N;
	cin >> N;

	int i = 1;
	while (i <= N) {
		int x;
		cin >> x;

		int idx = dq.size() - 1;
		while (1) {
			if (x <= dq[idx].first) {
				break;
			}
			else {
				idx = dq[idx].second;
			}
		}


		dq.push_back(pair<int, int>(x,idx));

		++i;
	}

	int idx = dq.size() - 1;

	for (int i = 1; i <= idx; i++) {
		cout << dq[i].second << " ";
	}

	return 0;
}