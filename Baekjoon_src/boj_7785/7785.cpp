#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> m;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string s1, s2;
	while (n--) {
		cin >> s1 >> s2;

		if (s2.compare("enter") == 0) {
			m[s1] = 1;
		}
		else if (s2.compare("leave") == 0) {
			m[s1] = 0;
		}
	}

	for (auto it = m.rbegin(); it != m.rend(); it++) {
		if (it->second == 1)
			cout << it->first << '\n';
	}

	return 0;
}
