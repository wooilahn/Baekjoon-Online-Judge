#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int map[1005][1005] = { 0 };
int ans[105] = { 0 };

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int x1, y1, w, h;
		scanf("%d %d %d %d", &x1, &y1, &w, &h);

		for (int x = x1; x < x1+w; x++) {
			for (int y = y1;y < y1+h;y++) {
				map[x][y] = i;
			}
		}
	}

	for (int i = 0; i <= 1002;i++) {
		for (int j = 0; j <= 1002; j++) {
			ans[map[i][j]]++;
		}
	}

	for (int i = 1; i <= N; i++)
		printf("%d\n", ans[i]);

	return 0;
}
