#include <iostream>
#include <deque>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string cmd;
	cin >> cmd;

	int fpos=-1;
	while (1) {
		fpos = cmd.find("()",fpos+1);
		if (fpos == string::npos)
			break;

		cmd.replace(fpos, 2, "|");
	}

	deque<int> stck;
	int r=0;
	int len = cmd.length();

	for (int i = 0; i < len; i++) {
		char c = cmd[i];

		if (c == '(') {
			stck.push_back(0);
		}
		else if (c == ')') {
			int t = stck.back();
			stck.pop_back();
			++t;
			r += t;
		}
		else {//c == '|'
			int size = stck.size();
			for (int j = 0; j < size; j++)
				stck[j] += 1;
		}
	}

	cout << r << "\n";

	return 0;
}