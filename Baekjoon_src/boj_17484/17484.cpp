#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M;

int map[10][10] = { 0 };
int dp[10][10][5] = {0}; 
int dc[4] = { 0, -1, 0, 1 };
int ans = INF;

int solve(int r, int c, int dir) {
	if (c < 1 || c > M)
		return INF;
	if (r == N)
		return map[r][c];

	int ret = dp[r][c][dir];

	if (ret != INF)
		return ret;

	for (int i = 1; i <= 3; i++) {
		if (i == dir)
			continue;

		ret = min(ret, map[r][c] + solve(r + 1, c + dc[i], i));
	}

	return ret;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			for (int k = 0; k < 5; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= M; i++) {
		ans = min(ans, solve(0, i, 0));
	}

	printf("%d\n", ans);

	return 0;
}
