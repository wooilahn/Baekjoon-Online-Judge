#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check_p(string ss) {
	for (int i = 0; i < ss.size()/2; i++) {
		if (ss[i] != ss[ss.size()-1-i])
			return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, k;
	cin >> T;

	while (T--) {
		cin >> k;
		bool flag = false;

		vector<string> sv;
		vector<int> v;
		string s;

		for (int i = 0; i < k - 2; i++)
			v.push_back(0);
		v.push_back(1);
		v.push_back(1);

		for (int i = 0; i < k; i++) {
			cin >> s;
			sv.push_back(s);
		}

		if (k == 1) {
			cout << "0\n";
			continue;
		}

		do {
			string s1 = "";
			string s2 = "";

			for (int i = 0; i < v.size(); i++) {
				if (v[i]) {
					if (s1 == "")
						s1 = sv[i];
					else if (s2 == "") {
						s2 = sv[i];
						break;
					}
				}
			}

			string ss1 = s1 + s2;
			string ss2 = s2 + s1;

			if (check_p(ss1)) {
				cout << ss1 << endl;
				flag = true;
				break;
			}
			else if (check_p(ss2)) {
				cout << ss2 << endl;
				flag = true;
				break;
			}

		} while (next_permutation(v.begin(), v.end()));

		if (!flag)
			cout << "0\n";
	}
	return 0;
}
