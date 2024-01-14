#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<string, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	string s;
	int p;

	for (int i = 0; i < N; i++) {
		cin >> s >> p;
		v.push_back(make_pair(s, p));
	}

	int sp;

	for (int i = 0; i < M; i++) {
		cin >> sp;

		int low = 0;
		int high = N - 1;
		int mid = N / 2;
		int ans = -1;

		while (low < high) {
			mid = (low + high) / 2;

			if (v[mid].second < sp) {
				low = mid + 1;
			}
			else if (v[mid].second >= sp) {
				high = mid;
			}
		}

		ans = low;
		cout << v[ans].first << "\n";
	}

	return 0;

}
