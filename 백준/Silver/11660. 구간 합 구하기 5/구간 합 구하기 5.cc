#include <iostream>
#include <deque>

using namespace std;

int arr[1025][1025] = { 0, };
int arraccul[1025][1025] = { 0, };

int n, m;

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			arraccul[i][j] = arraccul[i][j - 1] + arr[i][j];
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

	while (m-- > 0) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		long long sum = 0;
		for (int i = x1; i <= x2; i++) {
			sum+=(getAcculSum(i, y2) - getAcculSum(i, y1 - 1));
		}
		cout << sum<<"\n";
	}


	return 0;
}