#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int cnt = 0;

	while (s.size() > 1) {
		int sn = 0;

		for (int i = 0; i < s.size(); i++) {
			sn += s[i] - '0';
		}

		s = to_string(sn);
		cnt++;
	}

	cout << cnt << "\n";

	if ((s[0] - '0') % 3 == 0)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
