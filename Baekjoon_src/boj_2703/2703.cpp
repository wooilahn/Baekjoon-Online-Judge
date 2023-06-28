#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	string s, c;
	getline(cin, s);

	while (T--) {
		getline(cin, s);
		getline(cin, c);

		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = c[s[i] - 'A'];
			}
		}

		cout << s << endl;
	}

	return 0;
}
