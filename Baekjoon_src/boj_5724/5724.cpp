#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

long long dp[105] = { 0 };

int main() {
	int N;

	dp[1] = 1;
	
	for(int i=2; i<=100; i++)
		dp[i] = dp[i-1] + (i*i);

	while (true) {
		scanf("%d", &N);

		if (N == 0)
			break;

		printf("%lld\n", dp[N]);
	}

	return 0;
}
