#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int scores[105][105] = { 0 };
int times[105] = { 0 };
int trials[105] = { 0 };

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int n, k, t, m;
		scanf("%d %d %d %d", &n, &k, &t, &m); // n:팀의갯수, k:문제의갯수
		memset(scores, 0, sizeof(scores));
		memset(times, 0, sizeof(times));
		memset(trials, 0, sizeof(trials));

		for (int mm = 0; mm < m; mm++) {
			int i, j, s;
			scanf("%d %d %d", &i, &j, &s);
			scores[i][j] = max(scores[i][j], s);
			times[i] = max(times[i], mm);
			trials[i]++;
		}

		vector<pair< pair<int, int>, pair<int, int> >> v;

		for (int nn = 1; nn <= n; nn++) {
			int sum = 0;

			for (int kk = 0; kk <= k; kk++) {
				if (scores[nn][kk] > 0) {
					sum -= scores[nn][kk];
				}
			}

			v.push_back(make_pair(make_pair(sum, trials[nn]), make_pair(times[nn], nn)));
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			if (v[i].second.second == t)
				printf("%d\n", i + 1);
		}
	}

	return 0;
}
