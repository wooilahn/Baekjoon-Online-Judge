#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int T;
	scanf("%d", &T);

	while (T--) {
		long long x, y;
		scanf("%lld %lld", &x, &y);

		long long dis = y - x;

		if (dis == 1 || dis == 2) {
			printf("%lld\n", dis);
			continue;
		}
		else {
			for (long long i = 2;; i++) {
				long long target = i * i;

				if (target - i < dis && dis <= target + i) {
					if (target - i < dis && dis <= target) 
						printf("%lld\n", 2 * i - 1);
					else
						printf("%lld\n", 2 * i);

					break;
				}
			}
		}
	}

	return 0;
}
