#include <iostream>
#include <deque>
#include <string>


using namespace std;

int n;
deque<int> cmd;
string str;

int getmax(int start,int& idx) {
	int maxn = -1;
	for (int i = start; i <= n; i++) {
		if (maxn < cmd.at(i)) {
			maxn = cmd.at(i);
			idx = i;
		}
	}

	return maxn;
}

void swapn(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void parse() {
	for (int i = 0; i <= n - 1; i++) {
		char c = str[i];

		int x = c - '0';
		cmd.push_back(x);
	}
}

int main() {

	cin >> str;

	n = str.length();

	parse();

	--n;

	for (int i = 0; i <= n; i++) {
		int maxni = i;
		int maxn = getmax(i,maxni);

		swap(cmd.at(i), cmd.at(maxni));
	}

	str.clear()
		;

	for (int x : cmd) {
		str += (to_string(x));
	}

	cout << str;
	return 0;
}