#include <iostream>
#include <deque>


using namespace std;

typedef long long ll;

struct node {
	int idx;
	ll val;
};
int n, L;
deque<ll> arr;
deque<node> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> L;

	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		arr.push_back(x);
	}

	for (int i = 0; i <= L - 1; i++) {
		ll x = arr.at(i);

		while (dq.size() >= 1) {
			node n = dq.back();
			int nval = n.val;

			if (nval > x) {
				dq.pop_back();
			}
			else {
				break;
			}
		}

		dq.push_back({ i, x });

		cout << dq.front().val << " ";
	}

	int s = 1;
	int e = L;

	while (e <= n - 1) {
		ll x = arr.at(e);

		while (dq.size() >= 1) {
			node n = dq.back();
			int nval = n.val;

			if (nval > x) {
				dq.pop_back();
			}
			else {
				break;
			}
		}

		dq.push_back({ e, x });

		while(dq.front().idx < s) {
			dq.pop_front();
		}


		cout << dq.front().val << " ";

		++s;
		++e;
	}

	return 0;
}