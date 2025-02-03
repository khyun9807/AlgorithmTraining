#include <iostream>
#include <string>
#include <algorithm>

#include <deque>
#include <stack>
using namespace std;

int n;
stack<int> stck;

string result;

void func() {
	int marker = 0;

	int record = 1;

	cin >> n;

	while (n-- > 0) {
		int x;
		cin >> x;

		if (marker < x) {
			for (; record <= x; record++) {
				stck.push(record);
				result += "+\n";
			}

			stck.pop();
			result += "-\n";

			marker = x;
		}
		else if (marker > x) {
			bool success = false;
			while (!stck.empty()) {
				if (stck.top() > x) {
					stck.pop();
					result += "-\n";
				}
				else if (stck.top() == x) {
					stck.pop();
					result += "-\n";
					success = true;
					break;
				}
				else {//stck.top()<x
					result = "NO";
					return;
				}
			}
			if (!success) {
				result = "NO";
				return;
			}
		}
		else {
			result = "NO";
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	func();

	cout << result;


	return 0;
}