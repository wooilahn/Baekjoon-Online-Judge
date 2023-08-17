#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long ll;

ll dp[35][35] = { 0 };

void solve() {

	for (int H = 0; H <= 30; H++) { // 반알
		for (int W = 0; W <= 30; W++) { // 한알
			if (H > W)
				continue;
			else {
				if (H == 0)
					dp[W][H] = 1;
				else
					dp[W][H] = dp[W-1][H] + dp[W][H-1];
			}
		}
	}

	return;
}

int main() {
	int N;
	solve();

	while (true) {
		scanf("%d", &N);

		if (N == 0)
			break;
		else
			printf("%lld\n", dp[N][N]);

	}

	return 0;
}
