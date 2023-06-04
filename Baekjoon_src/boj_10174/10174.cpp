#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;

	cin >> n;
	getline(cin, s);
	
	while (n--) {
		getline(cin, s);
		bool flag = true;

		for (int i = 0; i < s.size() / 2; i++) {
			char c1 = tolower(s[i]);
			char c2 = tolower(s[s.size() - i - 1]);

			if (c1 != c2) {
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}
