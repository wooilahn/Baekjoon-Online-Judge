#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
int coins[6] = { 500, 100, 50, 10, 5, 1 };

int main() {

	int cost, remainder, ans = 0;

	scanf("%d", &cost);
	remainder = 1000 - cost;

	for (int i = 0; i < 6; i++) {
		int tmp = remainder / coins[i];

		ans += tmp;
		remainder -= (coins[i] * tmp);
	}

	printf("%d\n", ans);
	return 0;
}
