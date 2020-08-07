#define _CRT_SECURE_NO_WARNINGS
#define DIST_MAX 987654321
#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

int N, M;
vector < pair<long long, long long >> adj[502];
long long dist[502] = { 0 };

int bellman_ford(int n_trial) {
	int isChanged = 0;

	for (int round = 0; round < N; round++) { // round number
		for (int i = 1; i <= N; i++) { // all nodes
			for (int k = 0; k < adj[i].size(); k++) { // the edges corresponding to the node
				long long there = adj[i].at(k).first;					// Destination
				long long next_cost = dist[i] + adj[i].at(k).second;  // Cost corresponding to Destination

				if (dist[there] > next_cost && (dist[i] != INT_MAX)) {
					if (n_trial > 0)
						return ++isChanged;

					dist[there] = next_cost;
				}
			}
		}
	}

	return isChanged;
}

int main() {
	long long A, B, C;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%lld %lld %lld", &A, &B, &C);
		adj[A].push_back(make_pair(B, C));
	}

	for (int i = 1; i <= N; i++)
		dist[i] = INT_MAX;
	dist[1] = 0;

	bellman_ford(0);

	if (bellman_ford(1) == 1)
		printf("-1\n");
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INT_MAX)
				printf("-1\n");
			else
				printf("%lld\n", dist[i]);
		}
	}

	return 0;
}
