#include <iostream>
#include <stack>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	stack<char> stck;

	string cmd;
	cin >> cmd;

	int len = cmd.length();

	for (int i = 0; i <= len - 1; i++) {
		char c = cmd[i];

		if (c >= 'A' && c <= 'Z') {
			cout << c;
			continue;
		}

		//기호7
		if (c == '(') {
			stck.push(c);
		}
		else if (c == ')') {

			while (stck.top() != '(') {
				cout << stck.top();
				stck.pop();
			}

			stck.pop();
		}
		else if (c == '*' || c == '/') {
			if (stck.empty()) {
				stck.push(c);
				continue;
			}

			if (stck.top() == '*' || stck.top() == '/') {
				cout << stck.top();
				stck.pop();
			}

			while (!stck.empty()) {
				if (stck.top() == '(') {
					//stck.pop();
					break;
				}
				else if (stck.top() == '+' || stck.top() == '-') {
					break;
				}

				cout << stck.top();
				stck.pop();
			}

			stck.push(c);
		}
		else if (c == '+' || c == '-') {
			if (stck.empty()) {
				stck.push(c);
				continue;
			}

			while (!stck.empty()) {
				if (stck.top() == '(') {
					//stck.pop();
					break;
				}

				cout << stck.top();
				stck.pop();
			}

			stck.push(c);
		}
		

	}

	while (!stck.empty()) {
		if (stck.top() != '(')
			cout << stck.top();

		stck.pop();
	}

	return 0;
}