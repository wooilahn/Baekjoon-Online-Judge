#define _CRT_SECURE_NO_WARNINGS
#define TIME_MAX 1000000007
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <string.h>

using namespace std;

int N, M, K;
vector<pair<int, pair<int, int>>> adj[105];
int times[102][10002] = { 0 };

int dijkstra();

int main() {
	int T, ans;
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d %d", &N, &M, &K);        // n_node, n_cost, n_ticket

		for (int i = 0; i < K; i++) {
			int u, v, c, d;
			scanf("%d %d %d %d", &u, &v, &c, &d);	// source, dest, cost, distance(time)
			adj[u].push_back({ v, { c,d } });		// destination, (cost, distance(time))
		}

		ans = dijkstra();

		if (ans == TIME_MAX)
			printf("Poor KCM\n");
		else
			printf("%d\n", ans);

		for (int i = 0; i <= N; i++)
			adj[i].clear();
		memset(times, 0, sizeof(times));
	}

	return 0;
}

int dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pq;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			times[i][j] = TIME_MAX;
		}
	}

	times[1][0] = 0;
	pq.push({ 0, {0, 1} }); // (time, (dest, cost))

	while (!pq.empty()) {
		int cur_cost = -pq.top().first;
		int cur_time = pq.top().second.first;
		int here     = pq.top().second.second;
		pq.pop();

		if (cur_time > times[here][cur_cost] || cur_cost > M)
			continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here].at(i).first;
			int new_cost = adj[here].at(i).second.first + cur_cost;
			int new_time = adj[here].at(i).second.second + cur_time;

			if (new_cost > M)
				continue;

			if (times[there][new_cost] > new_time) {
				for (int i = new_cost; i <= M; i++) {
					if (times[there][i] > new_time)
						times[there][i] = new_time;
				}

				pq.push({ -new_cost, {new_time, there} });
			}
		}
	}

	int res = TIME_MAX;

	for (int i = 1; i <= M; i++)
		res = min(res, times[N][i]);

	return res;
}

