#define _CRT_SECURE_NO_WARNINGS
#define COST_MAX 987654321
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int n, m, sp, ep;
bool check[1005] = { 0 };
int costs[1005]  = { 0 };
int trace[1005]  = { 0 };
vector<pair<int, int>> adj[1005]; // first: dest, second: cost.

void dijkstra() {
	for (int i = 0; i <= n; i++) 
		costs[i] = COST_MAX;

	priority_queue<pair<int, int>> pq; // cost, source
	costs[sp] = 0;
	pq.push(make_pair(0, sp));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (cost > costs[here])
			continue;

		if (check[here])
			continue;
		else
			check[here] = true;

		for (int i = 0; i < adj[here].size(); i++) {
			int there     = adj[here].at(i).first;
			int next_cost = adj[here].at(i).second + cost;

			if (costs[there] > next_cost) {
				costs[there] = next_cost;
				trace[there] = here;
				pq.push(make_pair(-next_cost, there));
			}
		}
	}

	return;
}

int main() {
	scanf("%d\n%d", &n, &m);

	int source, dest, cost;

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &source, &dest, &cost);
		adj[source].push_back(make_pair(dest, cost));
	}

	scanf("%d %d", &sp, &ep);
	dijkstra();
	
	stack<int> s;
	s.push(ep);
	int t = trace[ep];

	while (t != 0) {
		s.push(t);
		t = trace[t];
	}

	printf("%d\n%d\n", costs[ep], s.size());

	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
	printf("\n");

	return 0;
}
