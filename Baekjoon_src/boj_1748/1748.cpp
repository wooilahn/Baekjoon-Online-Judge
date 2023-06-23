#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int ans = 0;
	int t = 1;
	int st = 1;

	while (true) {
		int nt = t * 10;

		if (nt > N) {
			ans += st * (N - t + 1);
			break;
		}
		else {
			ans += st * (nt - t);
			t = nt;
			st++;
		}
	}

	printf("%d\n", ans);

	return 0;
}
