#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int N;
int ans = 0;
int col[17] = { 0 };

bool promising(int cnt) {
	for (int k = 0; k < cnt; k++) {
		if (col[k] == col[cnt] || abs(col[k] - col[cnt]) == abs(k - cnt))
			return false;
	}

	return true;
}

void N_Queen(int cnt) {
	if (cnt == N) {
		ans++;
		return;
	}

	for (int k = 0; k < N; k++) {
		col[cnt] = k;
		if (promising(cnt))
			N_Queen(cnt + 1);
	}

	return;
}

int main() {
	scanf("%d", &N);
	N_Queen(0);
	printf("%d\n", ans);

	return 0;
}
