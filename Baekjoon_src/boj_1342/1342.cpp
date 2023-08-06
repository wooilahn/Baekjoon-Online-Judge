#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int arr[27] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	vector<int> v;
	vector<string> sv;
	
	for (int i = 0; i < s.size(); i++) {
		v.push_back(i+1);
		arr[s[i] - 'a']++;
	}

	int ans = 0;

	do {
		string st = "";
		for (int i = 0; i < v.size(); i++){
			st += s[v[i] - 1];
		}
		bool flag = false;

		for (int i = 0; i < st.size(); i++) {
			int prev_idx = i - 1;
			int next_idx = i + 1;

			if (prev_idx >= 0) {
				if (st[prev_idx] == st[i]) {
					flag = true;
					break;
				}
			}
			if (next_idx < st.size()) {
				if (st[next_idx] == st[i]) {
					flag = true;
					break;
				}
			}
		}

		if (!flag) {
			ans++;
		}
	} while (next_permutation(v.begin(), v.end()));

	int N = 1;

	for (int i = 0; i < 27; i++) {
		if (arr[i] > 0) {
			while (arr[i]) {
				N *= arr[i];
				arr[i]--;
			}
		}
	}
	
	cout << ans/N << "\n";
	return 0;
}
