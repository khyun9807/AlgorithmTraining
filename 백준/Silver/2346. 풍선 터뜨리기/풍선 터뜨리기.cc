#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	list<pair<int, int>> lt;

	deque<int> dq;



	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		lt.push_back(pair<int, int>(i, x));
	}


	list<pair<int, int>>::iterator liter=lt.begin();
	while (lt.size() >= 2) {
		dq.push_back((*liter).first);
		int val = (*liter).second;
		list<pair<int, int>>::iterator temp = liter;

		if (val >= 0) {
			++liter;
			if (liter == lt.end())
				liter = lt.begin();

			lt.erase(temp);
			
			for (int i = 0; i < val - 1; i++) {
				++liter;
				if (liter == lt.end())
					liter = lt.begin();
			}
		}
		else {
			val = -val;

			if (liter == lt.begin())
				liter = --lt.end();
			else
				--liter;

			lt.erase(temp);

			for (int i = 0; i < val - 1; i++) {
				if (liter == lt.begin())
					liter = --lt.end();
				else
					--liter;
			}
		}
	}



	dq.push_back((*(lt.begin())).first);

	int len = dq.size();
	for (int i = 0; i < len; i++) {
		cout << dq[i] << " ";
	}
	cout << "\n";
	return 0;
}