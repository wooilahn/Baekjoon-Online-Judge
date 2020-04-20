#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

bool prime[1005] = { 0 };

void func() {
	prime[1] = true;

	for (int i = 2; i <= 500; i++) {
		if (prime[i] == 0) {
			for (int j = i * 2; j <= 1000; j += i) {
				prime[j] = true;
			}
		}
	}
}

int main() {

	int N, tmp, ans = 0;
	scanf("%d", &N);

	func();

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);

		if (!prime[tmp])
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}
