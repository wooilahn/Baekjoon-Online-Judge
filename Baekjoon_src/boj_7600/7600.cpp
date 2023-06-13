#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		string s;
		getline(cin, s);

		int check[30] = { 0 };

		if (s[0] == '#' && s.size() == 1)
			break;

		for (int k = 0; k < s.size(); k++) {
			if ('A' <= s[k] && s[k] <= 'Z') {
				check[s[k]-'A']++;
			}
			else if ('a' <= s[k] && s[k] <= 'z') {
				check[s[k]-'a']++;
			}
		}

		int ans = 0;
		for (char c = 'a'; c <= 'z'; c++) {
			if (check[c - 'a'])
				ans++;
		}

		cout << ans << endl;
	}

	return 0;
}
