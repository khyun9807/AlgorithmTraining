

//22943번 다시풀기
//22942번
//3343번 다시풀기

#include <iostream>
#include <map>
#include <set>

using namespace std;

int N;
map<int, int> m;
set<int> points;
bool result;

void input() {
	result = true;

	cin >> N;

	for (int i = 0; i <= N - 1; i++) {
		int r, d;
		cin >> r >> d;

		int a = r - d;
		int b = r + d;

		if (points.find(a) != points.end()) {
			result = false;
			points.insert(a);
			continue;
		}

		if (points.find(b) != points.end()) {
			result = false;
			points.insert(b);
			continue;
		}

		m[a] = b;
	}
}

void solution() {
	map<int, int>::iterator miter = m.begin();

	int begins = (*miter).first;
	int ends = (*miter).second;
	int extraEnds = 1010001;


	for (++miter; miter != m.end(); miter++) {
		pair<int, int > p= *miter;

		if (extraEnds < p.first) {
			begins = p.first;
			ends = p.second;
			extraEnds = 1010001;
		}
		else if (p.second<ends) {//안 extra 갱신
			begins = p.first;

			extraEnds = ends;

			ends = p.second;
		}
		else if (ends < p.first) {//뒤 extra 유지
				if (p.second < extraEnds) {
					begins = p.first;
					ends = p.second;
				}
				else {
					result = false;
					return;
				}
			}
		else {//nah
			result = false;
			return;
		}



	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	if (!result) {
		cout << "NO\n";
		return 0;
	}
	
	solution();

	if (!result) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}

	return 0;
}