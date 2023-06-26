#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;

	while (true) {
		cin >> s;

		if (s == "#")
			break;

		int idx = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
				break;
			idx++;
		}

		cout << s.substr(idx, s.size()) << s.substr(0, idx) << "ay\n";
	}

	return 0;
}
