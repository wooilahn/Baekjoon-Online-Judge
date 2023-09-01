#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;

	cin >> s1 >> s2;

	long long ans = 0;

	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			ans += (s1[i] - '0') * (s2[j] - '0');
		}
	}

	cout << ans << "\n";

	return 0;
}
