#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> suc[1005];
int pre[1005] = { 0 };
int cost[1005] = { 0 };
int ans[1005] = { 0 };

int main() {

	int T;
	scanf("%d", &T);

	while (T--) {
		memset(suc, 0, sizeof(suc));
		memset(pre, 0, sizeof(pre));
		memset(cost, 0, sizeof(cost));
		memset(ans, 0, sizeof(ans));

		int N, K;
		scanf("%d %d", &N, &K);

		for (int i = 1; i <= N; i++) 
			scanf("%d", &cost[i]);
		
		for (int i = 0;i < K;i++) {
			int start, end;
			scanf("%d %d", &start, &end);

			pre[end]++;
			suc[start].push_back(end);
		}

		queue<int> q;

		for (int i = 1;i <= N;i++) {
			if (pre[i] == 0)
				q.push(i);
		}

		while (!q.empty()) {
			int base = q.front();
			q.pop();

			for (int i = 0;i < suc[base].size();i++) {
				int target = suc[base].at(i);

				ans[target] = max(ans[target], ans[base] + cost[base]);
				pre[target]--;

				if (pre[target] == 0)
					q.push(target);
			}
		}

		int W;
		scanf("%d", &W);
		printf("%d\n", ans[W] + cost[W]);
	}

	return 0;
}
