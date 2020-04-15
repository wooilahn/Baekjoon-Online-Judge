#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int T;
	int H, W, N;
	int x, y;
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d %d", &H, &W, &N);

		y = N % H;
		x = (N / H) + 1;

		if (y == 0) {
			y = H;
			x--;
		}


		printf("%d%02d\n", y, x);
	}

	return 0;
}
