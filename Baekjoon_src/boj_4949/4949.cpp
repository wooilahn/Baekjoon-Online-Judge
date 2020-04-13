#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

char str[105] = { 0 };

int main() {

	while (true) {
		fgets(str, sizeof(str), stdin);
		int len = strlen(str);

		str[len - 1] = 0;
		len--;

		if (len == 1 && str[0] == '.')
			return 0;

		bool flag = true;
		stack<char> s;

		for (int i = 0; i < len; i++) {
			if (str[i] == '(' || str[i] == '[') {
				if (s.empty())
					s.push(str[i]);
				else if (!s.empty() && (s.top() == ')' || s.top() == ']')) {
					flag = false;
					break;
				}
				else if (!s.empty() && (s.top() == '(' || s.top() == '[')) 
					s.push(str[i]);
			}
			else if(str[i] == ')'){
				if (s.empty()) {
					flag = false;
					break;
				}
				else if (!s.empty() && s.top() == '(')
					s.pop();
				else {
					flag = false;
					break;
				}
			}
			else if(str[i] == ']'){
				if (s.empty()) {
					flag = false;
					break;
				}
				else if (!s.empty() && s.top() == '[')
					s.pop();
				else {
					flag = false;
					break;
				}
			}
		}

		if (!s.empty())
			flag = false;

		if (flag == true)
			printf("yes\n");
		else if(flag == false)
			printf("no\n");
	}

	return 0;
}
