#include <iostream>

#include <deque>

using namespace std;



deque<deque<int>> matrix;

deque<bool> completed;
deque<bool> marked;

void stackdfs(int s) {
	deque<int> tracestack;

	tracestack.push_back(s);

	while (!tracestack.empty()) {
		int cur = tracestack.back();

		deque<int>& neighbors = matrix.at(cur);

		int target = -1;
		for (int neighbor : neighbors) {
			if (marked.at(neighbor) == false && completed.at(neighbor) == false) {
				target = neighbor;
				break;
			}
		}

		if (target == -1) {
			completed.at(cur) = true;

			tracestack.pop_back();
			marked.at(cur) = false;
		}
		else {
			tracestack.push_back(target);
			marked.at(target) = true;
		}
	}
}


int countbundle() {
	int result = 0;

	int len = matrix.size();
	--len;

	for (int i = 1; i <= len; i++) {
		if (completed.at(i) == false) {
			++result;
			stackdfs(i);
		}
	}

	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	matrix.assign(n + 1, {});
	completed.assign(n + 1, false);
	marked.assign(n + 1, false);

	for (int i = 1; i <= m; i++) {
		int s, d;
		cin >> s >> d;

		matrix.at(s).push_back(d);
		matrix.at(d).push_back(s);
	}

	int result = countbundle();

	cout << result;

	return 0;
}