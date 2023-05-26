#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int map[105][105] = { 0 };

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int x = x1; x <= x2; x++) {
			for (int y = y1; y <= y2; y++) {
				map[x][y]++;
			}
		}
		
	}

	int ans = 0;
	for (int x = 1; x <= 100; x++) {
		for (int y = 1; y <= 100; y++) {
			if (map[x][y] > M)
				ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}
