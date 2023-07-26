#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

long long dp[10000002][2] = { 0 };

int main() {
	int n;
	scanf("%d", &n);

	if (n == 1) {
		printf("1\n");
		return 0;
	}

	dp[2][0] = 1; // 악수하지 않는 경우
	dp[2][1] = 1; // 악수를 하는 경우

	for (int i = 3; i <= n; i++) {
		dp[i][0] = dp[i-1][0]%10 + dp[i-1][1]%10; // 악수를 하지 않는 경우
		dp[i][1] = dp[i-1][0]%10; // 악수를 하는 경우	
	}

	long long ans = (dp[n][0]%10 + dp[n][1]%10) % 10;
	printf("%lld\n", ans);

	return 0;
}
