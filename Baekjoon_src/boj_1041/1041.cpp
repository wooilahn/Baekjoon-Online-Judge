#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> dice;

int main() {
	long long N, num;
	long long max_v = -1;
	long long ans = 0;
	long long min1=51, min2=101, min3=151;

	scanf("%lld", &N);

	for (int i = 0; i < 6; i++) {
		scanf("%lld", &num);
		dice.push_back(num);
		ans += dice[i];
		max_v = max(max_v, dice[i]);
	}

	if (N == 1) {
		printf("%lld\n", ans - max_v);
		return 0;
	}

	for (int i = 0; i < 6; i++) {
		min1 = min(min1, dice[i]);

		for (int j = i+1; j < 6; j++) {
			if (i + j == 5)
				continue;

			min2 = min(min2, dice[i] + dice[j]);

			for (int k = j+1; k < 6; k++) {
				if (j + k == 5 || i + k == 5)
					continue;

				min3 = min(min3, dice[i] + dice[j] + dice[k]);
			}
		}
	}

	ans = 0;
	ans += min3 * 4;
	ans += min2 * (8*N - 12);
	ans += min1 * (5*N*N - 16*N + 12);

	printf("%lld\n", ans);

	return 0;
}
