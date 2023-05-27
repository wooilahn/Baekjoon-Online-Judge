#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		int d_idx = -1;
		int d_v = -1;
		int cnt_n[10] = { 0 };

		for (int i = s.size()-1; i > 0; i--) {
			cnt_n[s[i] - '0']++;
			if (s[i-1] < s[i]) {
				d_idx = i-1;
				d_v = s[i-1] - '0';
				cnt_n[s[i-1] - '0']++;
				break;
			}
		}

		if (d_idx == -1) {
			cout << "BIGGEST\n";
			continue;
		}

		for (int i = 0; i < d_idx; i++) {
			cout << s[i];
		}

		for (int i = d_v + 1; i < 10; i++) {
			if (cnt_n[i] > 0) {
				cout << i;
				cnt_n[i]--;
				break;
			}
		}

		for (int i = 0; i < 10; i++) {
			for (int k = 0; k < cnt_n[i]; k++)
				cout << i;
		}
		cout << "\n";
	}

	return 0;
}
