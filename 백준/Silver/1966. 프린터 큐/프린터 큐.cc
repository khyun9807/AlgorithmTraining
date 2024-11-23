#include <iostream>

#include <set>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	deque<int> result;

	int cn;
	cin >> cn;

	while (cn-- > 0) {
		multiset<int, greater<int>> ms;
		deque<pair<int,int>> dq;
		
		int N, M;
		cin >> N;
		cin >> M;

		for (int i = 0; i < N; i++) {
			int x;
			cin >> x;
			ms.insert(x);

			dq.push_back(pair<int, int>(x, i));
		}

		int num = 1;
		while (!dq.empty()) {
			
			pair<int, int> temp = dq.front();
			int best = *(ms.begin());

			if (temp.first != best) {
				dq.pop_front();
				dq.push_back(temp);
				continue;
			}


			dq.pop_front();
			ms.erase(ms.begin());

			if (temp.second == M) {
				cout << num << "\n";
				break;
			}
			
			++num;
		}

	}



	return 0;
}