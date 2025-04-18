#include<iostream>
#include<string>
#include<deque>
#include<algorithm>

using namespace std;

//100,000,000
//256 1024 1024 256,000,000
//N 1,000,000
//M 1,000
//A 1,000,000,000

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	deque<long long> dq;
	dq.push_back(0);

	for (int i = 0; i <= n - 1; i++) {
		int x;
		cin >> x;
		dq.push_back(dq.at(i)+x);
	}
	dq.pop_front();
	//1 2 3 1 2
	//1 3 6 7 9
	//1 0 0 1 0

	for (int i = 0; i < dq.size(); i++) {
		dq.at(i) %= m;
	}

	long long count[1001] = { 0, };

	for (int i = 0; i < dq.size(); i++) {
		count[dq.at(i)]++;
	}

	long long sum = count[0];

	for (int i = 0; i <= m-1; i++) {
		long long c = count[i];
		if (c >= 2) {
			sum += (c*(c-1)/2);
		}
	}


	cout << sum;

	return 0;
}