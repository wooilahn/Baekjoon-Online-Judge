#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int N, R, C;
char map[105][105] = { 0 };
bool chk[105][105] = { 0 };

int dx[4] = { -1, -1, 1, 1 };
int dy[4] = { 1, -1, 1, -1 };

int main() {
	scanf("%d %d %d", &N, &R, &C);

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			map[i][j] = '.';
		}
	}

	map[R-1][C-1] = 'v';

	queue<pair<int, int>> q;
	q.push(make_pair(R-1, C-1));

	while (!q.empty()) {
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();

		if (chk[cur_r][cur_c])
			continue;
		else
			chk[cur_r][cur_c] = true;

		for (int i = 0; i < 4; i++) {
			int tmp_r = cur_r + dx[i];
			int tmp_c = cur_c + dy[i];

			if (tmp_r < 0 || tmp_r >= N || tmp_c < 0 || tmp_c >= N)
				continue;
			if (chk[tmp_r][tmp_c])
				continue;

			map[tmp_r][tmp_c] = 'v';
			q.push(make_pair(tmp_r, tmp_c));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}
