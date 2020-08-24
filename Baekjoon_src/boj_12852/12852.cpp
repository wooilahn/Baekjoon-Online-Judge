#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

int dp[1000005] = { 0 };
int tr[1000005] = { 0 };

int solve(int n) {
	int min_v = 987654321;
	int temp, trace;

	if (dp[n] != -1)
		return dp[n];

	if (n % 3 == 0) {
		temp = solve(n / 3);

		if (temp < min_v) {
			trace = n / 3;
			min_v = temp;
		}
	}

	if (n % 2 == 0) {
		temp = solve(n / 2);

		if (temp < min_v) {
			trace = n / 2;
			min_v = temp;
		}
	}

	temp = solve(n - 1);

	if (temp < min_v) {
		trace = n - 1;
		min_v = temp;
	}

	tr[n] = trace;
	return dp[n] = min_v + 1;
}

void print(int n) {
	printf("%d ", n);

	while (tr[n] != 1) {
		printf("%d ", tr[n]);
		n = tr[n];
	}

	printf("1\n");
}

int main() {
	int N;
	scanf("%d", &N);

	memset(dp, -1, sizeof(dp));
	dp[0] = dp[1] = 0;

	printf("%d\n", solve(N));
	print(N);

	return 0;
}
