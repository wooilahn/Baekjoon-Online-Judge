#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

int N, M, K;
int A[15][15] = { 0 };
int cur_A[15][15] = { 0 };
int size_map[15][15] = { 0 };

deque<int> tree_map[15][15];
queue<pair<pair<int, int>, int>> summer_q;
queue<pair<int, int>> fall_q;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void solve() {
	int ans = 0;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			sort(tree_map[r][c].begin(), tree_map[r][c].end());
		}
	}

	for (int i = 1; i <= K; i++) { // year
		ans = 0;

		// spring
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				int die_n = 0;

				for (int k = 0; k < tree_map[r][c].size(); k++) {
					ans++;
					int cur_tree_age = tree_map[r][c].at(k);

					if (cur_tree_age <= cur_A[r][c]) {
						cur_A[r][c] -= cur_tree_age;
						tree_map[r][c].at(k) = cur_tree_age + 1;

						if ((cur_tree_age + 1) % 5 == 0)
							fall_q.push(make_pair(r, c));
					}
					else {
						summer_q.push(make_pair(make_pair(r, c), cur_tree_age));
						die_n++;
					}
				}

				while(die_n--)
				  tree_map[r][c].pop_back();

				cur_A[r][c] += A[r][c]; // winter
			}
		}

		// summer
		while (!summer_q.empty()) {
			ans--;
			int summer_r = summer_q.front().first.first;
			int summer_c = summer_q.front().first.second;
			int summer_yang = summer_q.front().second;
			summer_q.pop();

			cur_A[summer_r][summer_c] += (summer_yang / 2);
		}

		// fall
		while (!fall_q.empty()) {
			int fall_r = fall_q.front().first;
			int fall_c = fall_q.front().second;
			fall_q.pop();

			for (int t = 0; t < 8; t++) {
				int tmp_r = fall_r + dx[t];
				int tmp_c = fall_c + dy[t];

				if (tmp_r < 1 || tmp_c < 1 || tmp_r > N || tmp_c > N)
					continue;

				ans++;
				tree_map[tmp_r][tmp_c].push_front(1);
			}
		}
	}

	printf("%d\n", ans);
	return;
}

void Init() {
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			cur_A[i][j] = 5;
		}
	}

	int x, y, z;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &z);
		tree_map[x][y].push_back(z);
	}

	return;
}

int main() {
	Init();
	solve();
	return 0;
}
