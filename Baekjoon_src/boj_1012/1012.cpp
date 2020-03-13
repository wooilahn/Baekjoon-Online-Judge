#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int chk[55][55] = { 0 };
int map[55][55] = { 0 };

int ans;

void bfs(int x, int y);

int main() {

	int T;
	scanf("%d", &T);

	while (T--) {
		int m, n, k;
		scanf("%d %d %d", &m, &n, &k);

		ans = 0;
		memset(chk, 0, sizeof(chk));
		memset(map, 0, sizeof(map));

		for (int i = 0; i < k; i++) {
			int x, y;
			scanf("%d %d", &x, &y);

			map[x][y] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1 && chk[i][j] == 0) {
					bfs(i, j);
					ans++;
				}
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}

void bfs(int x, int y) {

	queue<pair<int, int>> cabbage;
	cabbage.push(make_pair(x, y));

	while (!cabbage.empty()) {
		int cur_x = cabbage.front().first;
		int cur_y = cabbage.front().second;
		cabbage.pop();

		if (chk[cur_x][cur_y] == 1) 
			continue;

		chk[cur_x][cur_y] = 1;

		map[cur_x][cur_y] = 1;
		for (int i = 0; i < 4; i++) {
			int tmp_x = cur_x + dx[i];
			int tmp_y = cur_y + dy[i];

			if (tmp_x < 0 || tmp_y < 0 || tmp_x >= 50 || tmp_y >= 50)
				continue;
			else {
				if (chk[tmp_x][tmp_y] == 0 && map[tmp_x][tmp_y] == 1) {
					cabbage.push(make_pair(tmp_x, tmp_y));
				}
			}
		}
	}

	return;
}
