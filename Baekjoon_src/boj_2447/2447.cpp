#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

char ans[6570][6570] = { 0 };

void f(int sr, int sc, int er, int ec, int size) {
	if (sr == er && sc == ec) {
		ans[sr][sc] = '*';
		return;
	}

	f(sr, sc, sr + (size / 3) - 1, sc + (size / 3) - 1, size / 3);
	f(sr, sc + (size / 3), sr + (size / 3) - 1, sc + (size * 2 / 3) - 1, size / 3);
	f(sr, sc + (size * 2 / 3), sr + (size / 3) - 1, ec, size / 3);

	f(sr + (size / 3), sc, sr + (size * 2 / 3) - 1, sc + (size / 3) - 1, size / 3);
	f(sr + (size / 3), sc + (size * 2 / 3), sr + (size * 2 / 3) - 1, ec, size / 3);

	f(sr + (size * 2 / 3), sc, er, sc + (size / 3) - 1, size / 3);
	f(sr + (size * 2 / 3), sc + (size / 3), er, sc + (size * 2 / 3) - 1, size / 3);
	f(sr + (size * 2 / 3), sc + (size * 2 / 3), er, ec, size / 3);
}

int main() {

	int n;
	scanf("%d", &n);

	memset(ans, ' ', sizeof(ans));

	f(1, 1, n, n, n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}
