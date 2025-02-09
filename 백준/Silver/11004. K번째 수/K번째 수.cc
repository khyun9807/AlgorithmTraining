#include <iostream>
#include <deque>
#include <string>
#include <algorithm>


using namespace std;


void parse(string str, deque<int>& cmd) {
	int x = 0;
	bool neg = false;
	for (char c : str) {
		switch (c) {
		case' ':
			if (neg)
				x *= -1;
			cmd.push_back(x);
			x = 0;
			neg = false;
			break;
		case '-':
			neg = true;
			break;
		default:
			int n = c - '0';
			x = x * 10 + n;
			break;
		}
	}

	if (neg)
		x *= -1;
	cmd.push_back(x);
	return;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	int n;
	cin >> n;
	int k;
	cin >> k;

	string str;

	cin.ignore();

	getline(cin, str);

	deque<int> cmd;
	parse(str, cmd);

	make_heap(cmd.begin(), cmd.end());
	sort_heap(cmd.begin(), cmd.end());

	cout << cmd[k - 1];




	return 0;
}