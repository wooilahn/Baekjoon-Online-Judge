#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

using namespace std;
long long dist[405][405] = { 0 };

int main() {
	int V, E;
	long long a, b, c;
	long long ans = INT_MAX;

	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; i++) 
		for (int j = 1; j <= V; j++) 
			dist[i][j] = INT_MAX;
		
	
	for (int i = 0; i < E; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);

		if (dist[a][b] > c)
			dist[a][b] = c;
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				if (dist[j][i] + dist[i][k] < dist[j][k])
					dist[j][k] = dist[j][i] + dist[i][k];
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (ans > dist[i][i])
			ans = dist[i][i];
	}

	if (ans == INT_MAX)
		printf("-1\n");
	else
		printf("%lld\n", ans);

	return 0;
}
