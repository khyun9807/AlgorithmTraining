#include <iostream>
#include <deque>

using namespace std;

int n; int m;
deque<int> dq;
deque<int> accul;

void init() {
	dq.clear();
	accul.clear();
	dq.assign(n, - 1);
	accul.assign(n, - 1);
}

int getAcculSum(int idx) {
	if (idx == -1)
		return 0;
	
		if (accul.at(idx) != -1) {
			return accul[idx];
		}
		else {
			accul.at(idx) = dq.at(idx) + getAcculSum(idx - 1);
			return accul.at(idx);
		}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	init();

	for (int i = 1; i <= n; i++) {
		cin >> dq[i - 1];
	}
	accul[0] = dq[0];

	for (int i = 1; i <= m; i++) {
		int s, d; cin >> s >> d;
		--s; --d;

		cout<<getAcculSum(d)-getAcculSum(--s)<<"\n";
	}


	return 0;
}