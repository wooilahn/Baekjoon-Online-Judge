#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

using namespace std;

int cost[105][105];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cost[i][j] = 0;
			else
				cost[i][j] = 99999999;
		}
	}

	int start, end, c;

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &start, &end, &c);

		if(cost[start][end] > c)
			cost[start][end] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (cost[s][k] + cost[k][e] < cost[s][e]) {
					cost[s][e] = cost[s][k] + cost[k][e];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] >= 99999999)
				printf("0 ");
			else
				printf("%d ", cost[i][j]);
		}
		printf("\n");
	}

	return 0;
}
