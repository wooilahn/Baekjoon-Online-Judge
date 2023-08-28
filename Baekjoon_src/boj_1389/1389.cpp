#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int map[105][105] = { 0 };

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			map[i][j] = 9999;
		}
	}

	int A, B;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);

		map[A][B] = 1;
		map[B][A] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}

	int ans = 0;
	int ans_val = 999999;

	for (int i = 1; i <= N; i++) {
		int cur_val = 0;

		for (int k = 1; k <= N; k++)
			cur_val += map[i][k];

		if (cur_val < ans_val) {
			ans = i;
			ans_val = cur_val;
		}
	}

	printf("%d\n", ans);

	return 0;
}
