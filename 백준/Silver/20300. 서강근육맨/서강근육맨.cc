//3343번 다시풀기

//순서 있는 조합
//순서 없는 조합
//dfs bfs로 만들어 보기

#include <iostream>
#include <set>
#include <deque>

using namespace std;

multiset<unsigned long long , greater<unsigned long long >> w;
deque<unsigned long long > mw;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		unsigned long long x;
		cin >> x;
		w.insert(x);
	}

	mw.assign(w.begin(), w.end());

	unsigned long long m;

	if (n % 2 == 1) {
		m = mw.front();
		mw.pop_front();
	}
	else
		m = 0;

 	while (1) {
		if (mw.empty())
			break;

		unsigned long long a = mw.front();
		mw.pop_front();
		unsigned long long b = mw.back();
		mw.pop_back();

		unsigned long long c = a + b;

		if (m < c)
			m = c;
	}

	cout << m;
	return 0;
}