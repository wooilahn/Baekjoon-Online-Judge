#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

struct FISH {
	int x;
	int y;
	int dir;
	bool live;
};

int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int map[4][4] = { 0 };
FISH fish[20];

int ans = 0;

void CopyState(int A[][4], int B[][4], FISH C[], FISH D[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			A[i][j] = B[i][j];
		}
	}

	for (int i = 1; i <= 16; i++) {
		C[i] = D[i];
	}

	return;
}

void SwapFish(int fish1, int fish2) {
	FISH tmp_fish = fish[fish1];
	fish[fish1].x = fish[fish2].x;
	fish[fish1].y = fish[fish2].y;
	fish[fish2].x = tmp_fish.x;
	fish[fish2].y = tmp_fish.y;
}

void MoveFish() {
	for (int i = 1; i <= 16; i++) {
		if (fish[i].live == false)
			continue;

		int f_x = fish[i].x;
		int f_y = fish[i].y;
		int f_dir = fish[i].dir;

		int tmp_x = f_x + dx[f_dir];
		int tmp_y = f_y + dy[f_dir];
		int find_flag = false;

		if (tmp_x >= 0 && tmp_y >= 0 && tmp_x < 4 && tmp_y < 4) {
			if (map[tmp_x][tmp_y] == 0) {
				find_flag = true;
				fish[i].x = tmp_x;
				fish[i].y = tmp_y;
				map[tmp_x][tmp_y] = i;
				map[f_x][f_y] = 0;
			}
			else if (map[tmp_x][tmp_y] != -1) {
				find_flag = true;
				SwapFish(i, map[tmp_x][tmp_y]);
				swap(map[f_x][f_y], map[tmp_x][tmp_y]);
			}
		}

		// 남은 8방향을 반시계 방향으로 돌려가며
		if (find_flag == false) {
			int tmp_dir = f_dir + 1;

			if (tmp_dir == 9)
				tmp_dir = 1;

			int tmp_x = f_x + dx[tmp_dir];
			int tmp_y = f_y + dy[tmp_dir];

			while (tmp_dir != f_dir) {
				if (tmp_x >= 0 && tmp_y >= 0 && tmp_x < 4 && tmp_y < 4) {
					if (map[tmp_x][tmp_y] == 0) {
						map[tmp_x][tmp_y] = i;
						map[f_x][f_y] = 0;
						fish[i].x = tmp_x;
						fish[i].y = tmp_y;
						fish[i].dir = tmp_dir;
						break;
					}
					else if (map[tmp_x][tmp_y] != -1) {
						SwapFish(i, map[tmp_x][tmp_y]);
						swap(map[f_x][f_y], map[tmp_x][tmp_y]);
						fish[i].dir = tmp_dir;
						break;
					}
				}

				tmp_dir++;
				if (tmp_dir == 9)
					tmp_dir = 1;
				tmp_x = f_x + dx[tmp_dir];
				tmp_y = f_y + dy[tmp_dir];
			}
		}
	}

	return;
}

void ChangeState(int s_x, int s_y, int t_x, int t_y, int fish_num, bool t_flag) {
	if (t_flag) { // true
		map[s_x][s_y] = 0;
		map[t_x][t_y] = -1;
		fish[fish_num].live = false;
	}
	else if (!t_flag) { // false
		map[s_x][s_y] = -1;
		map[t_x][t_y] = fish_num;
		fish[fish_num].live = true;
	}

	return;
}

void solve(int x, int y, int dir, int sum) {
	ans = max(ans, sum);

	int tmp_map[4][4] = { 0 };
	FISH tmp_fish[20];
	CopyState(tmp_map, map, tmp_fish, fish);

	// 1. 물고기 이동
	MoveFish();

	// 2. 샤크 이동 (경우의 수 최대 3가지)
	for (int i = 1; i <= 3; i++) {
		int tmp_x = x + dx[dir] * i;
		int tmp_y = y + dy[dir] * i;

		if (tmp_x >= 0 && tmp_y >= 0 && tmp_x < 4 && tmp_y < 4) {

			if (map[tmp_x][tmp_y] == 0)
				continue;

			int target_fish = map[tmp_x][tmp_y];
			int tmp_dir = fish[target_fish].dir;

			ChangeState(x, y, tmp_x, tmp_y, target_fish, true);
			solve(tmp_x, tmp_y, tmp_dir, sum + target_fish);
			ChangeState(x, y, tmp_x, tmp_y, target_fish, false);
		}
		else
			break;
	}

	CopyState(map, tmp_map, fish, tmp_fish);
	return;
}

int main() {
	int num, dir;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d %d", &num, &dir);
			map[i][j] = num;
			fish[num] = { i, j, dir, true };
		}
	}

	int F_num = map[0][0];
	int shark_dir = fish[F_num].dir;
	fish[F_num].live = false;
	map[0][0] = -1;

	solve(0, 0, shark_dir, F_num);
	printf("%d\n", ans);
	return 0;
}
