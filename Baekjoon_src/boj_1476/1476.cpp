#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);

	int cnt = 1;

	while (true) {
		int earth = (cnt % 15); // 0~14
		int sun   = (cnt % 28); // 0~27
		int moon  = (cnt % 19); // 0~18

		if (earth == 0)
			earth = 15;

		if (sun == 0)
			sun = 28;

		if (moon == 0)
			moon = 19;

		if (earth == E && sun == S && moon == M) {
			printf("%d\n", cnt);
			break;
		}

		cnt++;
	}

	return 0;
}
