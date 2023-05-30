#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

bool flag = false;
int D, K;
int dp[35] = { 0 };

void dfs(int idx) {
	if (flag)
		return;

	if (idx == 1 && dp[3] >= 2) {
		int A, B;

		B = dp[2];
		A = dp[3] - dp[2];

		if (A >= 1 && B >= 1 && A <= B) {
			printf("%d\n%d\n", A, B);
			flag = true;
			return;
		}
	}

	int val = dp[idx + 2] - dp[idx+1];

	if (val < 1)
		return;
	else {
		dp[idx] = val;
		dfs(idx - 1);
	}


	return;
}

int main() {
	scanf("%d %d", &D, &K);
	dp[D] = K;
	
	for (int t = 1; t <= K - 1; t++) {
		dp[D-1] = t;
		dfs(D-2);

		if (flag)
			break;
	}
	return 0;
}
