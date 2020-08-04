#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int N, E, v1, v2;
vector<pair<int, int>> adj[805];

int dijkstra(int sv ,int ev);

int main() {
	scanf("%d %d", &N, &E);
	int start, end, cost;
		
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &start, &end, &cost);
		adj[start].push_back(make_pair(end, cost));
		adj[end].push_back(make_pair(start, cost));
	}

	scanf("%d %d", &v1, &v2);

	int c1, c2, c3, c4, c5, c6;
	int ans1, ans2;

	c1 = dijkstra(1, v1);
	c2 = dijkstra(v1, v2);
	c3 = dijkstra(v2, N);

	if (c1 == INT_MAX || c2 == INT_MAX || c3 == INT_MAX)
		ans1 = INT_MAX;
	else
		ans1 = c1 + c2 + c3;

	c4 = dijkstra(1, v2);
	c5 = dijkstra(v2, v1);
	c6 = dijkstra(v1, N);

	if (c4 == INT_MAX || c5 == INT_MAX || c6 == INT_MAX)
		ans2 = INT_MAX;
	else
		ans2 = c4 + c5 + c6;

	int ans = min(ans1, ans2);

	if (ans == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}

int dijkstra(int sv, int ev) {
	bool check[805] = { 0 };
	priority_queue<pair<int, int>> pq;
	vector<int> costs(N+1, INT_MAX);

	costs[sv] = 0;
	pq.push(make_pair(0, sv));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (check[here])
			continue;
		else
			check[here] = 1;

		if (cost > costs[here])
			continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int there     = adj[here].at(i).first;
			int next_cost = cost + adj[here].at(i).second;

			if (costs[there] > next_cost) {
				costs[there] = next_cost;
				pq.push(make_pair(-next_cost, there));
			}
		}
	}

	return costs[ev];
}
