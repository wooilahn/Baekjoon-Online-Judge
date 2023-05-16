#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int map[5][5] = { 0 };

int check_bingo() {

	int p1_cnt = 0;
	int p1_cnt2 = 0;

	int p2_cnt = 0;
	int p2_cnt2 = 0;

	for (int i = 1; i <= 3; i++) {
		p1_cnt = 0;
		p2_cnt = 0;
		p1_cnt2 = 0;
		p2_cnt2 = 0;

		for (int k = 1; k <= 3; k++) {
			if (map[i][k] == 1)
				p1_cnt++;
			if (map[i][k] == 2)
				p2_cnt++;
			if (map[k][i] == 1)
				p1_cnt2++;
			if (map[k][i] == 2)
				p2_cnt2++;
		}

		if (p1_cnt == 3 || p1_cnt2 == 3)
			return 1;
		if (p2_cnt == 3 || p2_cnt2 == 3)
			return 2;
	}

	int p1_cntd = 0;
	int p1_cntd1 = 0;

	int p2_cntd = 0;
	int p2_cntd1 = 0;

	for (int i = 1; i <= 3; i++) {
		if (map[i][i] == 1)
			p1_cntd++;
		if (map[i][i] == 2)
			p2_cntd++;

		if (map[i][4 - i] == 1)
			p1_cntd1++;
		if (map[i][4 - i] == 2)
			p2_cntd1++;
	}

	if (p1_cntd == 3 || p1_cntd1 == 3)
		return 1;
	if (p2_cntd == 3 || p2_cntd1 == 3)
		return 2;

	return 0;
}

int main() {
	int turn;
	scanf("%d", &turn);

	int x, y;
	for (int i = 0; i < 9; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = turn;

		if (turn == 1)
			turn = 2;
		else if (turn == 2)
			turn = 1;

		int res = check_bingo();

		if (res > 0) {
			printf("%d\n", res);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
