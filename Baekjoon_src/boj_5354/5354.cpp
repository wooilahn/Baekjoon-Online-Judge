#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int n;
		scanf("%d", &n);

		if (n == 1) {
			printf("#\n\n");
			continue;
		}

		for (int i = 0; i < n; i++)
			printf("#");
		printf("\n");

		for (int k = 0; k < n - 2; k++) {
			printf("#");
			for (int i = 0; i < n - 2; i++)
				printf("J");
			printf("#\n");
		}

		for (int i = 0; i < n; i++)
			printf("#");
		printf("\n");

		printf("\n");
	}

	return 0;
}
