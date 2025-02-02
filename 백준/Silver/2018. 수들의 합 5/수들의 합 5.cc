#include <iostream>
#include <deque>


using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	int i=1;
	int j=1;
	int count = 0;
	int sum = 0;

	cin >> n;

	while (i <= n) {
		if (sum < n) {
			sum += j;
			++j;
		}
		else {
			if (sum == n) {
				++count;
			}
			sum -= i;
			++i;
		}
	}

	cout << count;

	return 0;
}