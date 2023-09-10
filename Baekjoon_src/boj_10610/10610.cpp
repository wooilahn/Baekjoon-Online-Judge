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

	long long jd = 0;
	long long z_cnt = 0;

	for (int i = 0; i < s.size(); i++) {
		jd += s[i] - '0';
		if (s[i] == '0')
			z_cnt++;
	}

	if (z_cnt == 0 || jd % 3 != 0) {
		cout << "-1" << "\n";
		return 0;
	}

	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());

	cout << s << "\n";

	return 0;
}


