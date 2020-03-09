#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int N;
double ans;
double pos[22][2];
bool chk[22];

void solve(int cnt, int idx);

int main() {

	int T;

	scanf("%d", &T);

	while (T--) {
		ans = 999999999;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) 
			scanf("%lf %lf", &pos[i][0], &pos[i][1]);

		solve(0, 0);
		printf("%lf\n", ans);
	}

	return 0;
}

void solve(int cnt, int idx) {
	
	if (cnt == N / 2) {
		double tmp_x = 0.0, tmp_y = 0.0;

		for (int i = 0; i < N; i++) {
			if (chk[i] == true) {
				tmp_x += pos[i][0];
				tmp_y += pos[i][1];
			}
			else if (chk[i] == false) {
				tmp_x -= pos[i][0];
				tmp_y -= pos[i][1];
			}
		}

		ans = min(ans, sqrt(tmp_x * tmp_x + tmp_y * tmp_y));
		return;
	}

	if (idx == N)
		return;
	
	solve(cnt, idx + 1);
	chk[idx] = true;
	solve(cnt + 1, idx + 1);
	chk[idx] = false;

	return;
}
