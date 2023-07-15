#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s1, s2;
	int cnt = 0;

	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++) {
		if (s1.substr(i, s2.size()) == s2)
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}
