#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

long long dp[32][32] = { 0 };

int main() {

	int T;
	scanf("%d", &T);

	while (T--) {
		int N, M;
		scanf("%lld %lld", &N, &M);

		for (int i = 1; i <= M; i++) {
			dp[i][0] = 1;
			dp[i][i] = 1;
			dp[i][1] = i;
		}

		for (int i = 3; i <= M; i++) {
			for (int j = 2; j < i; j++) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}

		printf("%lld\n", dp[M][N]);
	}

	return 0;
}
