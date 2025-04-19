#include <iostream>
#include <string>

using namespace std;

// 1초 100,000,000연산
// 256 * 1024 * 1024 바이트

//N 1,000,000
//ai < 10억 => int

//19 % 3 = 1
//(3 + 8 + 8) % 3
// (4 + 7 + 8) %3

void parse(string& cmd, long long* arr) {
	int i = 1;
	long long num = 0;
	for (char& c : cmd) {
		if (c == ' ') {
			arr[i] = num;
			i++;
			num = 0;
		}
		else {
			num = num * 10 + (c - '0');
		}
	}

	arr[i] = num;
}

long long countarr[1001] = { 0, };
long long arr[1000001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n, m;
	cin >> n >> m;
	cin.ignore();

	string cmd;
	getline(cin, cmd);
	parse(cmd, arr);


	for (int i = 1; i <= n; i++) {

		arr[i] += arr[i - 1];
	}


	for (int i = 1; i <= n; i++) {
		countarr[arr[i] % m]++;
	}

	long long sum = countarr[0];
	for (int i = 0; i <= m - 1; i++) {
		long long c = countarr[i];
		if (c >= 2) {
			sum += (c * (c - 1) / 2);
		}
	}

	cout << sum;

	return 0;
}

//1 3 6 7 9