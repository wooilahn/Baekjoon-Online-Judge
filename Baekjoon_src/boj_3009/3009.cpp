#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector <pair<int, int>> v;

int main() {

	int x, y;

	for (int i = 0;i < 3;i++) {
		scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}

	int ans_x, ans_y;

	for (int i = 0;i < 3;i++) {
		int tx = v.at(i).first;
		int ty = v.at(i).second;
		int x_cnt = 0, y_cnt = 0;

		for (int k = 0;k < 3;k++) {
			if (tx == v.at(k).first)
				x_cnt++;
			if (ty == v.at(k).second)
				y_cnt++;
		}

		if (x_cnt == 1)
			ans_x = tx;
		if (y_cnt == 1)
			ans_y = ty;
	}

	printf("%d %d\n", ans_x, ans_y);

	return 0;
}
