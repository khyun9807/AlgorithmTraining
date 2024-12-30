//22943번 다시풀기
//3343번 다시풀기
#include <iostream>
#include <deque>

using namespace std;

deque<bool> isprime;
deque<int> primelist;

int K, M;
int mx=1;
int mn=1;

void input() {
	cin >> K >> M;

	for (int i = 1; i <= K; i++) {
		mx *= 10;
		mn *= 10;
	}
	--mx;
	mn /= 10;
}

void getPrime() {
	isprime.assign(mx + 1, true);
	isprime[0] = false;
	isprime[1] = false;

	for (int i = 1; i <= mx; i++) {
		if (isprime[i]) {
			int curnum = i;

			int j = 2;
			while (curnum * j <= mx) {
				isprime[curnum * j] = false;
				++j;
			}
		}
	}

	for (int i = 1; i <= mx; i++) {
		if (isprime[i]) {
			primelist.push_back(i);
		}
	}
}

deque<bool> isconded;
void checkComb() {
	isconded.assign(mn, false);
	isconded.resize(mx + 1, true);

	for (int i = mn; i <= mx; i++) {
		int curnum = i;

		deque<bool> comb(10, false);

		int rem = 10;
		int div = 1;
		while (1) {
			if (rem > curnum * 10 && curnum * 10 >= div) {
				break;
			}

			int cal = curnum % rem / div;

			if (comb[cal]) {
				isconded[curnum] = false;
				break;
			}

			comb[cal] = true;

			rem *= 10;
			div *= 10;
		}
	}

}

deque<int> finallist;
void checkMulti() {
	int ps = primelist.size();

	for (int i = mn; i <= mx; i++) {
		int curnum = i;

		if (isconded[curnum]) {
			int x = curnum;
			while (x % M == 0) {
				x = x / M;
			}
			int remain = x;

			//remain값에 대한 캐시를 적용할 수도 있음.

			bool isright = false;

			for (int j = 0; j <= ps - 1; j++) {
				int primenum = primelist[j];

				if (primenum >= remain)
					break;

				if (remain % primenum == 0) {
					if (isprime[remain / primenum]) {
						isright = true;
						break;
					}
				}
			}
			
			if (!isright)
				isconded[curnum] = false;
		}
	}

	for (int i = mn; i <= mx; i++) {
		if (isconded[i])
			finallist.push_back(i);
	}
}

deque<int> result;
void checkSum() {
	int size = finallist.size();
	int ps = primelist.size();

	for (int i = 0; i <= size - 1; i++) {
		int curnum = finallist[i];

		for (int j = 0; j <= ps - 1; j++) {
			int t = curnum - primelist[j];

			if (t == primelist[j])
				continue;

			if (t <= 1)
				break;

			if (isprime[t]) {
				result.push_back(curnum);
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	getPrime();

	checkComb();

	checkMulti();

	checkSum();

	cout << result.size();

	return 0;
}