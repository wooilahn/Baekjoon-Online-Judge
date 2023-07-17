#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int Ta[305] = { 0 };

int main() {
	int T, n;
	scanf("%d", &T);

	Ta[1] = 1;
	for (int i = 2; i <= 303; i++)
		Ta[i] = Ta[i - 1] + i;

	while (T--) {
		int sum = 0;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
			sum += Ta[i+1] * i;
		printf("%d\n", sum);
	}

	return 0;
}
