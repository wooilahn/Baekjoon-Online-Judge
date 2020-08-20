#define _CRT_SECURE_NO_WARNINGS
#define COST_MAX 1000*1000+1
#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[1000][3] = { 0 };
int cost[1000][3] = { 0 };

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &cost[i][j]);
		}
	}

	int ans = COST_MAX;

	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 3; i++) {
			if (i == k)
				dp[0][i] = cost[0][i];
			else
				dp[0][i] = COST_MAX;
			
		}

		for (int i = 1; i < N; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}

		for (int i = 0; i < 3; i++) {
			if (i == k)
				continue;
			else
				ans = min(ans, dp[N - 1][i]);
		}
	}

	printf("%d\n", ans);

	return 0;
}
