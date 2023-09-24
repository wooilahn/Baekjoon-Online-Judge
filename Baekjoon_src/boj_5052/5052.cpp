#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		bool flag = false;
		vector<string> sv;

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			sv.push_back(s);
		}

		sort(sv.begin(), sv.end());

		for (int i = 0; i < sv.size() - 1; i++) {
			string cs = sv[i];
			string ns = sv[i + 1];

			if (cs.length() > ns.length())
				continue;

			if (cs == ns.substr(0, cs.length())) {
				flag = true;
				break;
			}
		}

		if (!flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
