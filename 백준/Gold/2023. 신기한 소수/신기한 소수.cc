#include <iostream>

#include <deque>

#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	deque<int> box;

	box.push_back(2);
	box.push_back(3);
	box.push_back(5);
	box.push_back(7);

	int n;
	cin >> n;

	while (n-->0) {
		int len = box.size();

		for (int i = 0; i <= len - 1; i++) {
			int num = box.front();
			box.pop_front();
			if(n==0)
				cout << num << "\n";

			num *= 10;
			for (int j = 0; j <= 9; j++) {
				int nn = num + j;

				int max = (int)(sqrt(nn));

				bool check = false;
				for (int q = 2; q <= max; q++) {
					if (nn % q == 0) {
						check = true;
						break;
					}
				}

				if (!check) {
					box.push_back(nn);
				}
			}
		}

	}


	return 0;
}