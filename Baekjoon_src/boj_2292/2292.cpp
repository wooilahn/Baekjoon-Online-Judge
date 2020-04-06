#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int N, cur = 1, cnt = 1;
	scanf("%d", &N);

	while (true) {
		if (cur >= N) {
			printf("%d\n", cnt);
			break;
		}

		cur += 6 * cnt;
		cnt++;
	}

	return 0;
}
