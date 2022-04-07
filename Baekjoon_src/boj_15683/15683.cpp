#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int map[10][10] = { 0 };
vector<pair<pair<int, int>, int>> cctv;

int ans = 99999;

int sum_blindspot() {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)
				sum++;
		}
	}

	return sum;
}

void copy_map(int co_map[][10]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			co_map[i][j] = map[i][j];
		}
	}
}

void return_map(int co_map[][10]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = co_map[i][j];
		}
	}
}

void cctv_1(int x, int y, int dir) { // dir: 1(동), 2(서), 3(남), 4(북)
	if (dir == 1) { // 동(y++)
		for (int i = y; i < M; i++) {
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}
	}
	else if (dir == 2) { // 서(y--)
		for (int i = y; i >= 0; i--) {
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}
	}
	else if (dir == 3) { // 남(x++)
		for (int i = x; i < N; i++) {
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}
	}
	else if (dir == 4) { // 북(x--)
		for (int i = x; i >= 0; i--) {
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}
	}

	return;
}

void cctv_2(int x, int y, int dir) { // dir: 1(동,서), 2(남,북)
	if (dir == 1) {
		for (int i = y; i >= 0; i--) {
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}

		for (int i = y; i < M; i++) {
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}
	}
	else if (dir == 2) {
		for (int i = x; i >= 0; i--) {
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}

		for (int i = x; i < N; i++) {
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}
	}

	return;
}

void cctv_3(int x, int y, int dir) { // dir: 1(동, 북), 2(서, 북), 3(서, 남), 4(동, 남)
	if (dir == 1) { // 동(y++), 북(x--)
		for (int i = y; i < M; i++) {
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}

		for (int i = x; i >= 0; i--) {
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}
	}
	else if (dir == 2) { // 서(y--), 북(x--)
		for (int i = y; i >= 0; i--) {
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}

		for (int i = x; i >= 0; i--) {
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}
	}
	else if (dir == 3) { // 서(y--), 남(x++)
		for (int i = y; i >= 0; i--) {
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}

		for (int i = x; i < N; i++) {
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}
	}
	else if (dir == 4) { // 동(y++), 남(x++)
		for (int i = y; i < M; i++) {
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}

		for (int i = x; i < N; i++) {
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}
	}

	return;
}

void cctv_4(int x, int y, int dir) {  // 1: 동, 서, 북   2: 서 남 북  3: 동 서 남   4: 동 남 북
	if (dir == 1) {
		for (int i = y; i >= 0; i--) { // 서
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}

		for (int i = y; i < M; i++) { // 동
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}

		for (int i = x; i >= 0; i--) { // 북
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}
	}
	else if (dir == 2) {
		for (int i = y; i >= 0; i--) { // 서
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}

		for (int i = x; i < N; i++) { // 남
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}

		for (int i = x; i >= 0; i--) { // 북
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}
	}
	else if (dir == 3) {
		for (int i = y; i >= 0; i--) { // 서
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}

		for (int i = y; i < M; i++) { // 동
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}

		for (int i = x; i < N; i++) { // 남
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}
	}
	else if (dir == 4) {
		for (int i = y; i < M; i++) { // 동
			if (map[x][i] == 6)
				break;
			else if (map[x][i] == 0)
				map[x][i] = -1;
		}

		for (int i = x; i < N; i++) { // 남
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}

		for (int i = x; i >= 0; i--) { // 북
			if (map[i][y] == 6)
				break;
			else if (map[i][y] == 0)
				map[i][y] = -1;
		}
	}

	return;
}

void cctv_5(int x, int y) {
	for (int i = y; i < M; i++) { // 동 (y++)
		if (map[x][i] == 6)
			break;
		else if (map[x][i] == 0)
			map[x][i] = -1;
	}

	for (int i = y; i >= 0; i--) { // 서 (y--)
		if (map[x][i] == 6)
			break;
		else if (map[x][i] == 0)
			map[x][i] = -1;
	}


	for (int i = x; i < N; i++) { // 남 (x++)
		if (map[i][y] == 6)
			break;
		else if (map[i][y] == 0)
			map[i][y] = -1;
	}

	for (int i = x; i >= 0; i--) { // 북 (x--)
		if (map[i][y] == 6)
			break;
		else if (map[i][y] == 0)
			map[i][y] = -1;
	}
}

void solve(int idx) {
	if (idx == cctv.size()) {
		ans = min(ans, sum_blindspot());
		return;
	}

	int c_x = cctv.at(idx).first.first;
	int c_y = cctv.at(idx).first.second;
	int cctv_type = cctv.at(idx).second;

	int c_map[10][10] = { 0 };
	copy_map(c_map);

	// 1일때 (경우의 수 4가지)
	if (cctv_type == 1) {
		cctv_1(c_x, c_y, 1);
		solve(idx + 1);
		return_map(c_map);

		cctv_1(c_x, c_y, 2);
		solve(idx + 1);
		return_map(c_map);

		cctv_1(c_x, c_y, 3);
		solve(idx + 1);
		return_map(c_map);

		cctv_1(c_x, c_y, 4);
		solve(idx + 1);
		return_map(c_map);
	}
	// 2일때 (경우의 수 2가지)
	else if (cctv_type == 2) {
		cctv_2(c_x, c_y, 1);
		solve(idx + 1);
		return_map(c_map);

		cctv_2(c_x, c_y, 2);
		solve(idx + 1);
		return_map(c_map);
	}
	// 3일때 (경우의 수 4가지)
	else if (cctv_type == 3) {
		cctv_3(c_x, c_y, 1);
		solve(idx + 1);
		return_map(c_map);

		cctv_3(c_x, c_y, 2);
		solve(idx + 1);
		return_map(c_map);

		cctv_3(c_x, c_y, 3);
		solve(idx + 1);
		return_map(c_map);

		cctv_3(c_x, c_y, 4);
		solve(idx + 1);
		return_map(c_map);
	}
	// 4일때 (경우의 수 4가지)
	else if (cctv_type == 4) {
		cctv_4(c_x, c_y, 1);
		solve(idx + 1);
		return_map(c_map);

		cctv_4(c_x, c_y, 2);
		solve(idx + 1);
		return_map(c_map);

		cctv_4(c_x, c_y, 3);
		solve(idx + 1);
		return_map(c_map);

		cctv_4(c_x, c_y, 4);
		solve(idx + 1);
		return_map(c_map);
	}
	// 5일때 (경우의 수 1가지)
	else if (cctv_type == 5) {
		cctv_5(c_x, c_y);
		solve(idx + 1);
		return_map(c_map);
	}

	return;
}


int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] >= 1 && map[i][j] <= 5)
				cctv.push_back(make_pair(make_pair(i, j), map[i][j]));
		}
	}

	solve(0);
	printf("%d\n", ans);

	return 0;
}

