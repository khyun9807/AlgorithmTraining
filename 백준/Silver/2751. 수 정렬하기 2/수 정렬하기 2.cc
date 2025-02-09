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

void swapn(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void qsort(deque<int>& cmd, int start, int end) {
	if (start >= end)
		return;

	int piv = start;

	swapn(cmd.at(piv), cmd.at((start + end) / 2));

	int s = start + 1;
	int e = end;

	if (s == e) {
		if (cmd.at(s) < cmd.at(piv)) {
			swapn(cmd.at(s), cmd.at(piv));
		}
		return;
	}

	while (true) {
		for (; s <= end - 1; s++) {
			if (cmd.at(s) > cmd.at(piv)) {
				break;
			}
		}

		for (; e >= start + 1 + 1; e--) {
			if (cmd.at(e) <= cmd.at(piv)) {
				break;
			}
		}

		if (e == s) {
			if (cmd.at(s) < cmd.at(piv)) {
				swapn(cmd.at(s), cmd.at(piv));
			}
			break;
		}
		else if (e < s) {
			swapn(cmd.at(e), cmd.at(piv));
			break;
		}
		else {//s<e
			swapn(cmd.at(s), cmd.at(e));
		}

	}

	if (e == s) {
		qsort(cmd, start, s - 1);
		qsort(cmd, s + 1, end);
	}
	else if (e < s) {
		qsort(cmd, start, e - 1);
		qsort(cmd, s, end);
	}


	return;
}

void mergesort(deque<int>& cmd, int start, int end) {
	if (start == end)
		return;

	int mid = (start + end) / 2;

	mergesort(cmd, start, mid);
	mergesort(cmd, mid + 1, end);

	deque<int> temp;

	int lefti = start;
	int righti = mid + 1;

	while (lefti <= mid && righti <= end) {
		if (cmd.at(lefti) <= cmd.at(righti)) {
			temp.push_back(cmd.at(lefti));
			++lefti;
		}
		else {
			temp.push_back(cmd.at(righti));
			++righti;
		}
	}

	if (lefti > mid) {
		while (righti <= end) {
			temp.push_back(cmd.at(righti));
			++righti;
		}
	}
	else if (righti > end) {
		while (lefti <= mid) {
			temp.push_back(cmd.at(lefti));
			++lefti;
		}
	}

	int len = temp.size() - 1;
	for (int i = 0; i <= len; i++) {
		cmd.at(i + start) = temp.at(i);
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;


	string str;



	deque<int> cmd;
	//parse(str, cmd);
	while (n-- > 0) {
		int x;
		cin >> x;
		cmd.push_back(x);
	}


	//mergesort(cmd, 0, cmd.size() - 1);
    sort(cmd.begin(),cmd.end());

	str.clear();

	for (int x : cmd) {
		str += (to_string(x) + "\n");
	}



	cout << str;
	return 0;
}