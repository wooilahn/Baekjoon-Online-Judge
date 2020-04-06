#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	bool flag = false;
	int N, ans = 5001;
	scanf("%d", &N);

	int limit = N / 5;

	for (int i = 0;i <= limit;i++) {
		int tmp = N, cur = 0;

		tmp = N - (i * 5);
		cur += i;

		if (tmp % 3 == 0) {
			cur += tmp / 3;

			if (ans > cur)
				ans = cur;
			
			flag = true;
		}
	}

	if (flag)
		printf("%d\n", ans);
	else
		printf("-1\n");

	return 0;
}
