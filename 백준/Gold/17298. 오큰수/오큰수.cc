#include <iostream>
#include <string>
#include <algorithm>

#include <deque>
#include <stack>
using namespace std;

string str;
deque<int> cmd;

struct node {
	int idx;
	int val;
};

deque<node> record;
deque<node> result;
int n;

void parse() {
	int num = 0;
	for (char c : str) {
		if (c == ' ') {
			cmd.push_back(num);
			num = 0;
		}
		else {
			num = num * 10 + (c - '0');
		}
	}
	cmd.push_back(num);
}

void init() {
	cin >> n;
	cin.ignore();
	getline(cin, str);
	parse();
	str.clear();
	record.assign(n, { 0,0 });
	result.assign(n, { 0,0 });
	
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	int idx = n - 1;
	record.at(idx) = { -1,-1 };
	--idx;

	for (; idx >= 0; idx--) {
		if (cmd.at(idx) < cmd.at(idx+1)) {
			record.at(idx) = { idx + 1,cmd.at(idx + 1) };
		}
		else {
			int jdx = idx + 1;
			while (cmd.at(idx) >= record.at(jdx).val) {
				jdx = record.at(jdx).idx;
				if (jdx == -1)
					break;
			}
			if (jdx == -1)
				record.at(idx) = { -1,-1 };
			else
				record.at(idx) = { record.at(jdx).idx,record.at(jdx).val };
		}
	}

	for (node n : record) {
		int x = n.val;

		string t = to_string(x)+" ";

		str += t;
	}
	cout << str;
	return 0;
}