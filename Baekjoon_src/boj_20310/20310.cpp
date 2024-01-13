#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int c0 = 0;
	int c1 = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') 
			c0++;
		else if (s[i] == '1')
			c1++;
	}

	c0 /= 2;
	c1 /= 2;

	while (c0) {
		int idx = s.size();

		for (int i = idx; i >= 0; i--) {
			if (s[i] == '0') {
				s.erase(i, 1);
				c0--;
				break;
			}
		}
	}

	while (c1) {
		int idx = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				s.erase(i, 1);
				c1--;
				break;
			}
		}
	}

	cout << s << endl;

	return 0;
}
