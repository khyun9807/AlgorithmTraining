#include <iostream>

#include <deque>


using namespace std;

int tc;

string cmd;

deque<char> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> tc;

	while (tc-- > 0) {
		cin >> cmd;

		int length = cmd.length();

		int i = 0;

		for (; i < length; i++) {
			char c = cmd[i];

			if (c == '(') {
				dq.push_back(c);
			}
			else if (c == ')') {
				if (dq.empty()) {
					break;
				}
				else
					dq.pop_back();
			}
		}

		if (i < length)
			cout << "NO" << "\n";
		else if (!dq.empty())
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";

		dq.clear();
		cmd.clear();
	}


	return 0;
}