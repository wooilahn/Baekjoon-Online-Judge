#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

long long ans[205][205] = { 0 };

int main() {

	int N, K;
	scanf("%d %d", &N, &K);

	ans[1][1] = 1;

	for (int i = 0; i <= 200; i++) 
		ans[0][i] = 1;
	
	for (int i = 2; i <= 200; i++) {
		ans[1][i] = 1;
		ans[i][1] = 1;
		ans[1][i] += ans[1][i - 1];
	}

	for (int i = 2; i <= 200; i++) { // first index
		for (int k = 2; k <= 200; k++) { // second index
			for (int t = 0; t <= i; t++) {
				ans[i][k] += ans[t][k - 1];
				ans[i][k] %= 1000000000;
			}
		}
	}
	
	printf("%lld\n", ans[N][K]);
	return 0;
}
