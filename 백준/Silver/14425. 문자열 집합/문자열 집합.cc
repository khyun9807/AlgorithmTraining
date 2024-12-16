#include <iostream>

#include <set>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		multiset<string> set;

	int n; cin >> n;
	int m; cin >> m;
	for (int i = 1; i <= n; i++) {
		string x; cin >> x;

		set.insert(x);
	}

	int result = 0;
	for (int i = 1; i <= m; i++) {
		string x; cin >> x;

		result += set.count(x);
	}

	cout << result;

	return 0;
}