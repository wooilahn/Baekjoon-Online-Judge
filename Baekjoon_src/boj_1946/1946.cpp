#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		vector<pair<int, int>> v;

		for (int i = 0; i < N; i++) {
			int s1, s2;
			cin >> s1 >> s2;
			v.push_back(make_pair(s1, s2));
		}

		sort(v.begin(), v.end());

		int ans = 1;
		int max_v = v[0].second;

		for (int i = 1; i < N; i++) {
			if (max_v < v[i].second)
				continue;

			ans++;
			max_v = v[i].second;
		}

		cout << ans << endl;
	}

	return 0;
}
