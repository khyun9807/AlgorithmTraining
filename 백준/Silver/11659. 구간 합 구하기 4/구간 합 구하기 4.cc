#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

deque<int> dq;
int n;
int qn;

deque<string> cmdq;

void parsing(string& cmd) {
	int num = 0;
	for (char& c : cmd) {
		switch (c) {
		case ' ':
			dq.push_back(num);
			num = 0;
			break;
		default:
			num = num * 10 + (c-'0');
			break;
		}
	}
	dq.push_back(num);
}

pair<int,int> parsing2(string& cmd) {
	pair<int, int> q;

	int num = 0;
	for (char& c : cmd) {
		switch (c) {
		case ' ':
			q.first = num;
			num = 0;
			break;
		default:
			num = num * 10 + (c - '0');
			break;
		}
	}
	q.second = num;

	return q;
}

void init() {
	cin >> n;
	cin >> qn;
	cin.ignore();

	string cmd;
	getline(cin, cmd);

	parsing(cmd);


	for (int i = 1; i <= qn; i++) {
		string cmd2;
		getline(cin, cmd2);
		cmdq.push_back(cmd2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	deque<int> sumdq;
	sumdq.push_back(dq.at(0));
	for (int i = 1; i <= n - 1; i++) {
		sumdq.push_back(sumdq.at(i - 1) + dq.at(i));
	}
	sumdq.push_front(0);

	string result = "";
	for (int i = 0; i <= qn - 1; i++) {
		pair<int,int> p=parsing2(cmdq.at(i));
		
		result+=(to_string(sumdq.at(p.second) - sumdq.at(p.first - 1))+"\n");
	}

	cout << result;

	return 0;
}