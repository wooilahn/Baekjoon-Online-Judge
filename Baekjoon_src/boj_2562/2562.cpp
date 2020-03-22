#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int tmp, ans = 0, cnt = 0;

	for (int i = 0;i < 9;i++) {
		scanf("%d", &tmp);

		if (tmp > ans) {
			ans = tmp;
			cnt = i + 1;
		}
	}

	printf("%d\n%d", ans, cnt);

	return 0;
}
