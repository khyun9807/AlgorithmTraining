#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int m; cin >> m;

	map<string, string> mp;
	
	for (int i = 1; i <= n; i++) {
		string x;
		cin >> x;

		string t = to_string(i);

		mp[x] = t;
		mp[t] = x;
	}

	for (int i = 1; i <= m; i++) {
		string x;
		cin >> x;

		cout << mp[x]<<"\n";
	}


	return 0;
}