#include <iostream>
#include <string>
#include <deque>

using namespace std;

int arraccul[1025][1025] = { 0, };

int n, m;

void parsing(string& cmd, int* arr) {
	int i = 0;
	int num = 0;
	for (char& c : cmd) {
		if (c == ' ') {
			arr[i] = num;
			num = 0;
			++i;
		}
		else {
			num = num * 10 + (c - '0');
		}
	}
	arr[i] = num;
}

void init() {
	cin >> n >> m;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		int temp[1025];
		string cmd;
		getline(cin, cmd);
		parsing(cmd, temp);

		for (int j = 1; j <= n; j++) {			
			arraccul[i][j] = arraccul[i][j - 1] + temp[j-1];
		}
	}
}

int getAcculSum(int a, int b) {
	return arraccul[a][b];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	string r = "";

	while (m-- > 0) {
		//int x1, y1, x2, y2;
		//cin >> x1 >> y1 >> x2 >> y2;

		int arr[4];

		string cmd;
		getline(cin, cmd);
		parsing(cmd, arr);
		int x1, y1, x2, y2;
		x1 = arr[0];
		y1 = arr[1];
		x2 = arr[2];
		y2 = arr[3];

		long long sum = 0;
		for (int i = x1; i <= x2; i++) {
			sum += (getAcculSum(i, y2) - getAcculSum(i, y1 - 1));
		}

		r += (to_string(sum) + "\n");
	}

	cout << r;

	return 0;
}