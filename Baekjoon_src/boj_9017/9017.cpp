#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v[205];

int main() {
	int T, N;
	scanf("%d", &T);

	while (T--) {
		for (int i = 0; i <= 201; i++)
			v[i].clear();

		vector<pair<int,pair<int,int>>> wv;

		scanf("%d", &N);
		int max_v = -1;
		int num;

		for (int i = 1; i <= N; i++) {
			scanf("%d", &num);
			v[num].push_back(i);
			max_v = max(num, max_v);
		}

		for (int i = 1; i <= max_v; i++) {
			if (v[i].size() >= 6)
				continue;

			for (int k = 1; k <= max_v; k++) {
				if (k == i)
					continue;

				for (int t = 0; t < v[k].size(); t++) {
					int cnt = 0;

					for (int idx = 0; idx < v[i].size(); idx++) {
						if (v[k][t] > v[i][idx])
							cnt++;
						else
							break;
					}

					v[k][t] -= cnt;
				}
			}
		}

		for (int i = 1; i <= max_v; i++) {
			if (v[i].size() < 6)
				continue;

			int sum = 0;

			for (int k = 0; k < 4; k++)
				sum += v[i][k];

			wv.push_back(make_pair(sum, make_pair(v[i][4], i)));
		}

		sort(wv.begin(), wv.end());
		printf("%d\n", wv[0].second.second);
	}

	return 0;
}
