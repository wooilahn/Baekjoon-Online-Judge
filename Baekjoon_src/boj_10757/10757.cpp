#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

stack<char> s1;
stack<char> s2;
stack<char> ans;

int main() {
	char str1[10005] = { 0 };
	char str2[10005] = { 0 };
	scanf("%s %s", str1, str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for (int i = 0; i < len1; i++) 
		s1.push(str1[i]);
	for (int i = 0; i < len2; i++)
		s2.push(str2[i]);

	int n1, n2, alpha = 0;

	while (!s1.empty() || !s2.empty()) {
		if (!s1.empty()) {
			n1 = s1.top() - '0';
			s1.pop();
		}
		else
			n1 = 0;

		if (!s2.empty()) {
			n2 = s2.top() - '0';
			s2.pop();
		}
		else
			n2 = 0;

		int res = n1 + n2 + alpha;

		alpha = res / 10;
		ans.push((res % 10) + '0');
	}

	if (alpha == 1)
		ans.push(alpha + '0');

	while (!ans.empty()) {
		printf("%c", ans.top());
		ans.pop();
	}
	printf("\n");

	return 0;
}
