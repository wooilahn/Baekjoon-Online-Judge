#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int map[10][10] = { 0 };
vector<pair<int, int>> v;

void dfs(int cnt);
bool row_check(int r, int num);
bool col_check(int c, int num);
bool sqr_check(int r, int c, int num);
bool pass(int r, int c, int num);

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 0)
				v.push_back(make_pair(i, j));
		}
	}

	dfs(0);
	return 0;
}

void dfs(int cnt) {

	if (cnt == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", map[i][j]);
			}

			printf("\n");
		}

		exit(0);
	}

	for (int i = 1; i <= 9; i++) {

		int pos_r = v.at(cnt).first;
		int pos_c = v.at(cnt).second;

		if (pass(pos_r, pos_c, i)) {
			map[pos_r][pos_c] = i;
			dfs(cnt + 1);
			map[pos_r][pos_c] = 0;
		}
	}

	return;
}

bool row_check(int r, int num) {
	for (int i = 0; i < 9; i++) {
		if (map[r][i] == num)
			return false;
	}

	return true;
}

bool col_check(int c, int num) {
	for (int i = 0; i < 9; i++) {
		if (map[i][c] == num)
			return false;
	}

	return true;
}

bool sqr_check(int r, int c, int num) {

	int s_r = (r/3) * 3, e_r = s_r + 2;
	int s_c = (c/3) * 3, e_c = s_c + 2;

	for (int i = s_r; i <= e_r; i++) {
		for (int j = s_c; j <= e_c; j++) {
			if (map[i][j] == num)
				return false;
		}
	}

	return true;
}

bool pass(int r, int c, int num) {
	if (row_check(r, num) && col_check(c, num) && sqr_check(r, c, num))
		return true;
	else
		return false;
}
