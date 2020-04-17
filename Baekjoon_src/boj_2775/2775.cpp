#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int dp[16][16] = { 0 };

void func() {
	for (int i = 1; i <= 14; i++) {
		dp[0][i] = i;
	}

	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			int sum = 0;

			for (int k = 1; k <= j; k++) {
				sum += dp[i - 1][k];
			}

			dp[i][j] = sum;
		}
	}
}

int main() {

	int T;
	int k, n;
	scanf("%d", &T);

	func();

	while (T--) {
		scanf("%d %d", &k, &n);
		printf("%d\n", dp[k][n]);
	}

	return 0;
}
