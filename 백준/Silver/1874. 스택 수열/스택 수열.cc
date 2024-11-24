#include <iostream>
#include <deque>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	deque<char> result;
	deque<int> stck;
	deque<int> demand;
	int resource = 1;
	set<int> trash;

	for (int i = 0; i < n; i++) {
		stck.push_back(i + 1);

		int x;
		cin >> x;

		demand.push_back(x);
	}

	while (!demand.empty()) {
		int target = demand.front();
		demand.pop_front();

		//목표가 쓰레기통에 있는지 확인
		if (trash.find(target) != trash.end()) {
			//있으면 NO
			cout << "NO" << "\n";
			return 0;
		}

		//목표는 resource 혹은 스택에
		//아래부터 "NO"할 상황은 없음.


		///if (stck.empty()) {//스택이 비어있음
			while (resource <= target) {
				stck.push_back(resource);
				result.push_back('+');
				++resource;
			}
		//}


		//if (!stck.empty() && stck.back() < target) {//스택이 안 비어있음.
		//}


		//


		if (!stck.empty() && stck.back() >= target) {//목표가 스택 안에 있을 때
			//여기서부터는 무조건 스택 안에 있음.
			//스택에서 찾기

			while (!stck.empty()) {
				int back = stck.back();
				stck.pop_back();
				result.push_back('-');
				trash.insert(back);

				if (back == target) {
					break;
				}
			}
			//빼고 기록하고 쓰레기 통에 넣고 찾기 완료.
		}
		else {//목표가 스택 안에 없을 때 (스택이 빈 것도 포함이지)
			//스택에 집어넣기
			//스택에서 찾기
		}

	}

	int len = result.size();
	for (int i = 0; i < len; i++)
		cout << result[i] << "\n";

	return 0;
}