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

void SORT(deque<int>& cmd) {
	int bound = cmd.size() - 1;
	for (int i = 1; i <= bound; i++) {
		int x = cmd.at(i);

		bool isInerted = false;

		for (int j = i-1; j >= 0; j--) {
			if (x < cmd.at(j)) {
				cmd.at(j + 1) = cmd.at(j);
			}
			else {//x>=cmd.at(j)
				cmd.at(j + 1) = x;
				isInerted = true;
				break;
			}
		}

		if (!isInerted) {
			cmd.at(0) = x;
		}
	}
}

int main() {
	int n;
	cin >> n;

	string str;

	cin.ignore();

	getline(cin, str);

	deque<int> cmd;
	parse(str, cmd);

	SORT(cmd);

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