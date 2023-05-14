#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int map[120][120] = { 0 };

int main() {
	int x1, y1, x2, y2;
	int sum = 0;

	for (int i = 0; i < 4; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				map[x][y]++;
			}
		}
	}

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (map[i][j])
				sum++;
		}
	}

	printf("%d\n", sum);

	return 0;
}
