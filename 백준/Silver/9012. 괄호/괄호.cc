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
		string result="YES";
		cin >> cmd;

		int length = cmd.length();

		for (int i = 0; i < length; i++) {
			char c = cmd[i];

			if (c == '(') {
				dq.push_back(c);
			}
			else if (c == ')') {
				if (dq.empty()) {
					result = "NO";
					break;
				}
				else
					dq.pop_back();
			}
		}


		if (!dq.empty())
			result = "NO";


		cmd.clear();
		dq.clear();

		cout << result << "\n";
	}


	return 0;
}