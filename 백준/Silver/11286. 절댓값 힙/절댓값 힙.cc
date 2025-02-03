#include <iostream>
#include <string>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
using namespace std;

typedef long long ll;

int n;
deque<ll> cmd;
string result;

struct node {
	ll val;
	ll abval;
	bool operator==(const node& n)const {
		if (abval == n.abval)
			return val == n.val;
		return false;
	}
	bool operator!=(const node& n)const {
		return !(*this == n);
	}
	bool operator< (const node & n)const {
		if (abval == n.abval)
			return val < n.val;
		return abval < n.abval;
	}
	bool operator> (const node& n)const {
		if (abval == n.abval)
			return val > n.val;
		return abval > n.abval;
	}
};
priority_queue < node, deque<node>, greater<node>> pq;

void init() {
	cin >> n;
	for (int i = 0; i <= n - 1; i++) {
		ll x;
		cin >> x;
		cmd.push_back(x);
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	for (int x : cmd) {
		if (x == 0) {
			if (pq.empty()) {
				result += "0\n";
			}
			else {
				string t = to_string(pq.top().val)+"\n";
				pq.pop();
				result += t;
			}
		}
		else {
			int ab = x > 0 ? x : -x;
			pq.push({ x,ab });
		}
	}

	cout << result;

	return 0;
}