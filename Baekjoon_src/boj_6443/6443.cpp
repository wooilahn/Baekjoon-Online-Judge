#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, len;
string ss;

void dfs(string s, int idx) {
	if (idx == len - 1) {
		cout << s << "\n";
		return;
	}

	for (int i = idx; i < len; i++) {
		if (i != idx && s[i] == s[idx]) {
			continue;
		}

		if (s[i] != s[idx]) {
			char tmp = s[i];
			s[i] = s[idx];
			s[idx] = tmp;
		}

		dfs(s, idx + 1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	while (N--) {
		cin >> ss;
		len = ss.size();

		sort(ss.begin(), ss.end());

		dfs(ss, 0);
	}

	return 0;
}
