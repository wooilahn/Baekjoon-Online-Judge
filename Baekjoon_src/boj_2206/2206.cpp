#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <queue>

using namespace std;

int map[1005][1005]    = { 0 }; // (x, y)
int chk[1005][1005][2] = { 0 }; // (x, y, b_w)

struct state {
	int x;   // coordinate x
	int y;   // coordinate y
	int b_w; // whether it breaks wall or not. (0: can break, 1: can't break)
	int cnt; // count
};

int N, M;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0 ,0, -1, 1 };
int db[2] = { 0, 1 };
int ans = INT_MAX;

void bfs();

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	bfs();

	if (ans == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n", ans+1);

	return 0;
}

void bfs() {
	state s;
	queue<state> q;

	s.x = 0, s.y = 0, s.b_w = 0, s.cnt = 0;
	chk[0][0][0] = 1;
	q.push(s);

	while (!q.empty()) {
		state q_s = q.front();
		q.pop();

		if (q_s.x == N - 1 && q_s.y == M - 1) {
			ans = min(ans, q_s.cnt);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			state tmp_s;
			tmp_s.x = q_s.x + dx[i];
			tmp_s.y = q_s.y + dy[i];

			if (tmp_s.x < 0 || tmp_s.y < 0 || tmp_s.x >= N || tmp_s.y >= M)
				continue;
			else {
				tmp_s.b_w = q_s.b_w;
				tmp_s.cnt = q_s.cnt + 1;

				if (map[tmp_s.x][tmp_s.y] == 0) {
					if (chk[tmp_s.x][tmp_s.y][tmp_s.b_w] == 0) {
						chk[tmp_s.x][tmp_s.y][tmp_s.b_w] = 1;
						q.push(tmp_s);
					}
				}
				else if (map[tmp_s.x][tmp_s.y] == 1 && tmp_s.b_w == 0) {
					tmp_s.b_w = 1;
					chk[tmp_s.x][tmp_s.y][tmp_s.b_w] = 1;
					q.push(tmp_s);
				}
			}
		}
	}

	return;
}
