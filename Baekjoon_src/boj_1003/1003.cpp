#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int dp[50][2] = { 0 };

int main() {

	int test;
	scanf("%d", &test);

	dp[0][0] = 1, dp[0][1] = 0;
	dp[1][0] = 0, dp[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	while (test--) {
		int n;
		scanf("%d", &n);

		printf("%d %d\n", dp[n][0], dp[n][1]);
	}

	return 0;
}
