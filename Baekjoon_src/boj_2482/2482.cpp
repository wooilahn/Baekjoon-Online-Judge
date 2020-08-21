#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int dp[1005][1005] = { 0 };
const int n_mod = 1000000003;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % n_mod;
		}
	}

	int ans = (dp[N - 1][K] + dp[N - 3][K-1]) % n_mod;
	printf("%d\n", ans);

	return 0;
}
