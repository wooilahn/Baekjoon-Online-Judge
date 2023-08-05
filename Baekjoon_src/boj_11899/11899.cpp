#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int lp = 0;
	int rp = 0;
	int ans = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			lp++;
		else if (s[i] == ')') {
			rp++;

			if (lp > 0) {
				lp--;
				rp--;
			}
		}
	}

	ans = lp + rp;
	cout << ans << endl;

	return 0;
}
