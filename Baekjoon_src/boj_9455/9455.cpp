#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

int map[105][105] = { 0 };

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int m, n;
		int ans = 0;

		scanf("%d %d", &m, &n);
		memset(map, 0, sizeof(map));


		for (int i = m-1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					for (int k = i-1; k >= 0; k--) {
						if (map[k][j] == 1) {
							ans += i - (k+1);

							int tmp = map[i][j];
							map[i][j] = map[k+1][j];
							map[k+1][j] = tmp;

							break;
						}

						if (k == 0) {
							ans += i;

							int tmp = map[i][j];
							map[i][j] = map[k][j];
							map[k][j] = tmp;
						}
					}
				}
			}
		}
		
		printf("%d\n", ans);
	}


	return 0;
}
