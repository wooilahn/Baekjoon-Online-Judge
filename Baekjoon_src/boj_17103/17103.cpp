#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
int prime[1000005] = { 0 };

void eratos() {
	prime[0] = 1;
	prime[1] = 1;

	for (int i = 2; i <= 500000; i++) {
		if (prime[i])
			continue;
		else {
			for (int k = i + i; k <= 1000000; k += i)
				prime[k] = 1;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	eratos();

	while (T--) {
		int n, ans = 0;
		scanf("%d", &n);

		for (int k = 2; k <= n / 2; k++) {
			if (!prime[k] && !prime[n-k])
				ans++;
		}

		printf("%d\n", ans);
	}

	return 0;
}
