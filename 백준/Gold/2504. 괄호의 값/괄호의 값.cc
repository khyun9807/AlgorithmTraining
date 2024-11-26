#include <iostream>
using namespace std;
#include <stack>
#include <algorithm>
#include <cstring>
int main() {
	char str[31] = { 0, };
	cin >> str;
	int size = strlen(str);

	stack<int> st;

	for (int i = 0; i < size; i++) {
		switch (str[i]) {
		case '(':case'[':
			st.push(str[i]);
			break;
		case ')':
			if (!st.empty() && st.top() == '(')
				st.pop();
			else {
				cout << 0;
				return 0;
			}
			break;
		case ']':
			if (!st.empty() && st.top() == '[')
				st.pop();
			else {
				cout << 0;
				return 0;
			}
			break;
		default:
			cout << 0;
			return 0;
		}
	}
	if (!st.empty()) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < size; i++) {
		switch (str[i]) {
		case '(':case'[':
			st.push(str[i]);
			break;
		case ')': {
			int sum = 0;
			while (st.top() != '(') {
				sum = sum + (st.top()*-1);
				st.pop();
			}
			st.pop();

			if (sum == 0)
				st.push(-2);
			else
				st.push(-2 * sum );
		}
				  break;
		case ']': {
			int sum = 0;
			while (st.top() != '[') {
				sum = sum + (st.top() *-1);
				st.pop();
			}
			st.pop();

			if (sum == 0)
				st.push(-3);
			else
				st.push(-3 * sum );
		}
				  break;
		}
	}

	
	int result = 0;
	while (!st.empty()) {
		result = result + (st.top()*-1);
		st.pop();
	}
	cout << result;
	return 0;
}

