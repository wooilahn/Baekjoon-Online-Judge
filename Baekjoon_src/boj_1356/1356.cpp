#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i] - '0');
	}

	int idx = 1;

	bool flag = false;

	while (true) {
		if (idx == v.size())
			break;

		int a = 1;
		int b = 1;

		for (int i = 0; i < v.size(); i++) {
			if (i < idx)
				a *= v[i];
			else
				b *= v[i];
		}

		if (a == b) {
			flag = true;
			break;
		}

		idx++;
	}

	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
