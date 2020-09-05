#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int stair[310] = { 0 };
int dp[310][3] = { 0 }; //0:1개일때, 1:2개일때

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &stair[i]);

	dp[1][0] = stair[1];
	dp[1][1] = 0;
	dp[2][0] = stair[2];
	dp[2][1] = stair[1] + stair[2];

	for (int i = 3; i <= n; i++) {
		dp[i][0] = max(dp[i - 2][1],dp[i-2][0]) + stair[i];
		dp[i][1] = dp[i - 1][0] + stair[i];
	}
	
	int ans = max(dp[n][0], dp[n][1]);
	printf("%d\n", ans);

	return 0;
}
