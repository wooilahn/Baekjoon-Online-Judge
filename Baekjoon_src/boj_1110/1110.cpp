#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);

	int cur = N, ans = 0;
	int a, b;

	do {
		a = cur / 10, b = cur % 10;
		cur = b * 10 + ((a + b) % 10);
		ans++;
	} while (cur != N);

	printf("%d\n", ans);

	return 0;
}
