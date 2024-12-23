//20955번 다시 풀기
//4315번 풀기
//트리 문제 그래프 말고 트리로 바라보며 다시 풀어보기.


#include <iostream>
#include <list>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	list<int> lt;

	int N, K;
	cin >> N >> K;

	for (int i = 2; i <= N; i++)
		lt.push_back(i);

	int count = 0;

	while (1) {
		int t = *(lt.begin());
		int q = 1;

		list<int>::iterator liter = lt.begin();
		while (liter != lt.end()) {

			int v = *liter;

			if (v == t * q) {
				++count;

				if (count == K) {
					cout << v;
					return 0;
				}

				liter = lt.erase(liter);
				++q;
			}
			else if (v>t*q) {
				while (v > t * q)
					++q;
			}
			else
				++liter;
			
		}
	}

	return 0;
}