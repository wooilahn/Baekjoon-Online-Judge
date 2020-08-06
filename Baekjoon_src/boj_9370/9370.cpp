#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, t;
int s, g, h;
int a, b, d;

vector<pair<int, int>> graph[2002];

int dijkstra(int s_v, int e_v) {
	int check[2002] = { 0 };
	vector<int> dist(n+1, 987654321);
	priority_queue<pair<int, int>> pq;

	dist[s_v] = 0;
	pq.push(make_pair(0, s_v));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (check[here])
			continue;
		else
			check[here] = 1;

		if (cost > dist[here])
			continue;

		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here].at(i).first;
			int next_cost = cost + graph[here].at(i).second;

			if (dist[there] > next_cost) {
				dist[there] = next_cost;
				pq.push(make_pair(-next_cost, there));
			}
		}
	}

	return dist[e_v];
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		vector<int> ans;
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h); // target exists between g and h

		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &d);
			graph[a].push_back(make_pair(b, d));
			graph[b].push_back(make_pair(a, d));
		}

		for (int i = 0; i < t; i++) {
			int e, ans1, ans2, ans_c;
			scanf("%d", &e);

			ans_c = dijkstra(s, e);
			ans1  = dijkstra(s, g) + dijkstra(g, h) + dijkstra(h, e);
			ans2  = dijkstra(s, h) + dijkstra(h, g) + dijkstra(g, e);

			if (ans_c == ans1 || ans_c == ans2)
				ans.push_back(e);
		}

		sort(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans.at(i));
		printf("\n");

		for (int i = 0; i <= n; i++)
			graph[i].clear();
	}

	return 0;
}
