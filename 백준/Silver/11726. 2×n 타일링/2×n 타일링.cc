#include <string>
#include <iostream>
#include <deque>

using namespace std;

int n;
long long arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1]%10007 + arr[i - 2]%10007)%10007;
        
	}
	
	cout << arr[n] % 10007;

	return 0;
}
