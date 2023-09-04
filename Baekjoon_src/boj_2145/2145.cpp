#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;

	while (true) {
		cin >> s;

		if (s == "0")
			break;
		
		while (s.size() > 1) {
			int n = 0;

			for (int i = 0; i < s.size(); i++) {
				n += s[i] - '0';
			}

			s = to_string(n);
		}

		cout << s << "\n";
	}

	return 0;
}
