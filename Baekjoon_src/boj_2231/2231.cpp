#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int N, tmp, result;
	scanf("%d", &N);

	for (int i = 1; i <= 1000000; i++) {
		tmp = i, result = i;

		while (tmp != 0) {
			result += tmp % 10;
			tmp /= 10;
		}

		if (result == N) {
			printf("%d\n", i);
			return 0;
		}
	}

	printf("0\n");
	return 0;
}
