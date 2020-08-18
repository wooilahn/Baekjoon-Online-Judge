#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int cost[16][16] = { 0 };
int dp[16][1 << 16];

int tsp(int currentCity, int visited) {
	int& ret = dp[currentCity][visited];

	if (ret != -1)
		return ret;

	if (visited == (1 << N) - 1) {
		if (cost[currentCity][0] != 0)
			return cost[currentCity][0];
		else
			return 987654321;
	}

	ret = 987654321;

	for (int i = 0; i < N; i++) {
		if (cost[currentCity][i] && !(visited & (1 << i))) {
			int visit = visited | (1 << i);
			ret = min(ret, tsp(i, visit) + cost[currentCity][i]);
		}
	}

	return ret;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &cost[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", tsp(0, 1));

	return 0;
}
