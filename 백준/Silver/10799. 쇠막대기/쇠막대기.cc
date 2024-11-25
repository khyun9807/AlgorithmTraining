#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	deque<char> stck;

	string cmd;
	cin >> cmd;

	int len = cmd.length();

	int r=0;
	for (int i = 0; i < len; i++) {
		char c = cmd[i];

		if (c == '(') {
			stck.push_back('(');
		}
		else {//c==')'
			char prev = cmd[i - 1];

			stck.pop_back();

			if (prev == '(') {
				r += stck.size();
			}
			else {//prev==')'
				r += 1;
			}
		}
	}

	cout << r << "\n";

	return 0;
}