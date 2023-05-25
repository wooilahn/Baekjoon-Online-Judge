#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	for (int i = N; i >= 0; i--) {
		int target = i;

		while (target) {
			int q = target % 10;

			if (q != 4 && q != 7)
				break;

			target /= 10;
		}

		if (target == 0) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}
