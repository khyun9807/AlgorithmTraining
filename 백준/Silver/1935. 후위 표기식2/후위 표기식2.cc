#include <iostream>
#include <deque>


using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	

	int N;
	string cmd;

	cin >> N;
	cin >> cmd;

	int len = cmd.length();
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		for (int j = 0; j < len; j++) {
			if (cmd[j] == 'A' + i)
				cmd[j] = x;
		}

	}

	deque<double> st;
	
	for (int i = 0; i < len; i++) {
		char c = cmd[i];

		if (c == '+') {
			double op2 = st.back();
			st.pop_back();
			double op1 = st.back();
			st.pop_back();

			double r = op1 + op2;
			st.push_back(r);
		}
		else if (c == '-') {
			double op2 = st.back();
			st.pop_back();
			double op1 = st.back();
			st.pop_back();

			double r = op1 - op2;
			st.push_back(r);
		}
		else if (c == '*') {
			double op2 = st.back();
			st.pop_back();
			double op1 = st.back();
			st.pop_back();

			double r = op1 * op2;
			st.push_back(r);
		}
		else if (c == '/') {
			double op2 = st.back();
			st.pop_back();
			double op1 = st.back();
			st.pop_back();

			double r = op1 / op2;
			st.push_back(r);
		}
		else {
			st.push_back(c);
		}

	}

	cout << fixed;
	cout.precision(2);

	cout << st.back() << "\n";

	return 0;
}