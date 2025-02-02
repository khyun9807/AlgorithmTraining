#include <iostream>
#include <deque>
#include <set>

using namespace std;

int n;
int m;
set<int> temp;
deque<int> arr;

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		temp.insert(x);
	}

	arr.assign(temp.begin(),temp.end());
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	int count = 0;
	int i = 0;
	int j = n - 1;

	while (i != j) {
		int sum = arr.at(i) + arr.at(j);
		if (sum == m) {
			++count;
			--j;
		}
		else if (sum > m) {
			--j;
		}
		else if (sum < m) {
			++i;
		}
	}
	cout << count;

	return 0;
}