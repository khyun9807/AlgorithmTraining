#include <iostream>
#include <deque>
#include <string>
#include <algorithm>


using namespace std;


void parse(string str, deque<int>& cmd) {
	int x=0;

	for (char c : str) {
		switch (c) {
		case' ':
			cmd.push_back(x);
			x = 0;
			break;
		default:
			int n = c - '0';
			x = x * 10 + n;
			break;
		}
	}

	cmd.push_back(x);
	return;
}

int main() {
	int n;
	cin >> n;

	string str;

	cin.ignore();

	getline(cin, str);

	deque<int> cmd;
	parse(str, cmd);

	sort(cmd.begin(), cmd.end());

	for (int i = 1; i <= n-1; i++) {
		cmd.at(i) += cmd.at(i - 1);
	}

	long long result = 0;
	for (int x : cmd) {
		result += x;
	}

	cout << result;
	

	return 0;
}