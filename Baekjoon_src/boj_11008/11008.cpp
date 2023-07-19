#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	string s, p;

	while (T--) {
		cin >> s >> p;

		while (true) {
			int pos = s.find(p);

			if (pos == string::npos)
				break;

			s.replace(pos, p.length(), "-");
		}

		cout << s.size() << "\n";
	}

	return 0;
}
