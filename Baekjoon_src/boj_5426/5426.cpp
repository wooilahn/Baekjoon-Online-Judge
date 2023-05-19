#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;
char str[10005] = { 0 };

char map[105][105] = { 0 };

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		scanf("%s", str);

		int m_len = sqrt(strlen(str));

		for (int i = 1; i <= m_len; i++) {
			for (int j = 1; j <= m_len; j++) {
				map[i][j] = str[(i - 1) * m_len + (j - 1)];
			}
		}

		for (int j = m_len; j >= 1; j--) {
			for (int i = 1; i <= m_len; i++) {
				printf("%c", map[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}
