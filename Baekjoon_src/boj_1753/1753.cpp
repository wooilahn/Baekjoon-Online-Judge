#define _CRT_SECURE_NO_WARNINGS
#define INF INT_MAX-1

#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

bool check[20005] = { 0 };
vector<pair<int, int>> adj[20005];

vector<int> djkstra(int v, int start) {
	
	vector<int> dist(v, INF);
	priority_queue<pair<int, int>> pq;

	dist[start] = 0;
	pq.push(make_pair(0, start));

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

		for (int i = 0;i < adj[here].size();i++) {
			int there = adj[here].at(i).first;
			int next_cost = cost + adj[here].at(i).second;

			if (dist[there] > next_cost) {
				dist[there] = next_cost;
				pq.push(make_pair(-next_cost, there));
			}
		}
	}

	return dist;
}

int main() {
	
	int V, E, K;

	scanf("%d %d", &V, &E);
	scanf("%d", &K);

	int u, v, w;

	for (int i = 0;i < E;i++) {
		scanf("%d %d %d", &u, &v, &w);
		adj[u].push_back(make_pair(v, w));
	}

	vector<int> ans = djkstra(V+1, K);

	for (int i = 1;i <= V;i++) {
		if (ans[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", ans[i]);
	}

	return 0;
}
