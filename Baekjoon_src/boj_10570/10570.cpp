#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

int cnt[1005] = { 0 };

int main() {

	int N, V;
	int num;

	scanf("%d", &N);

	while (N--) {
		scanf("%d", &V);
		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < V; i++) {
			scanf("%d", &num);
			cnt[num]++;
		}

		int ans = -1;
		int tcnt = -1;

		for (int i = 1; i <= 1000; i++) {
			if (tcnt < cnt[i]) {
				tcnt = cnt[i];
				ans = i;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
