#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	string s;

	cin >> T;
	// ABCDEFGHIJKLMNOPQRSTUVWXYZ

	while (T--) {
		cin >> s;
		int N = s.size();

		int idx = N - 1;

		while (true) {
			if (idx == 0)
				break;

			if (s[idx - 1] < s[idx])
				break;
			else
				idx--;
		}

		if (idx == 0) {
			cout << s << endl;
			continue;
		}

		int idx2 = N - 1;

		while (true) {
			if (idx2 == 0)
				break;

			if (s[idx - 1] < s[idx2])
				break;
			else
				idx2--;
		}

		char tmp = s[idx-1];
		s[idx - 1] = s[idx2];
		s[idx2] = tmp;

		for (int i = 0; i < idx; i++)
			cout << s[i];

		for (int i = N - 1; i >= idx; i--)
			cout << s[i];

		cout << "\n";
	}

	return 0;
}
