#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int R, C, A, B;
	scanf("%d %d %d %d", &R, &C, &A, &B);

	char t = 'X';
	char c = 'X';

	for (int i = 0; i < R; i++) {
		if (t == 'X')
			t = '.';
		else if (t == '.')
			t = 'X';

		for (int j = 0; j < A; j++) {
			c = t;

			for (int k = 0; k < C; k++) {
				if (c == 'X')
					c = '.';
				else if (c == '.')
					c = 'X';

				for (int l = 0; l < B; l++) {
					printf("%c", c);
				}
			}
			printf("\n");
		}
	}

	return 0;
}
