#include <iostream>
#include <algorithm>

#include<string>
#include <deque>

using namespace std;

enum {
	A=0,
	C,
	G,
	T
};

int conv(char c) {
	switch (c) {
	case'A':
		return A;
		break;
	case'C':
		return C;
		break;
	case'G':
		return G;
		break;
	case'T':
		return T;
		break;
	}
}

int an, cn, gn, tn;

int actg[4] = { 0, };

bool isGood() {
	if (an <= actg[A] && cn <= actg[C]) {
		if (gn <= actg[G] && tn <= actg[T]) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int slen;
	int plen;
	string str;
	cin >> slen >> plen >> str >> an >> cn >> gn >> tn;

	int count = 0;

	int s = 0;
	int e = plen - 1;
	for (int i = s; i <= e; i++) {
		++actg[conv(str[i])];
	}

	if (isGood())
		++count;

	while (e <= slen - 2) {
		++e;
		++actg[conv(str[e])];
		--actg[conv(str[s])];
		++s;

		if (isGood())
			++count;
	}

	cout << count;

	return 0;
}