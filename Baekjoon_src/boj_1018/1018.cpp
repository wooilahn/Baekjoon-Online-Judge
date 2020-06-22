#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

char plate[55][55] = { 0 };

int main() {
	int ans = 51 * 51;
	int cnt1;
	int cnt2;
	char base;

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) 
		scanf("%s", plate[i]);


	for (int sn = 0; sn < N - 7; sn++) {
		for (int sm = 0; sm < M - 7; sm++) {
			int en = sn + 8;
			int em = sm + 8;
			cnt1 = 0;
			cnt2 = 0;

			base = 'W';
			for (int n = sn; n < en; n++) {
				for (int m = sm; m < em; m++) {

					if (plate[n][m] == base)
						cnt1++;

					if (m != em - 1) {
						if (base == 'W')
							base = 'B';
						else if (base == 'B')
							base = 'W';
					}
				}
			}

			base = 'B';
			for (int n = sn; n < en; n++) {
				for (int m = sm; m < em; m++) {

					if (plate[n][m] == base)
						cnt2++;

					if (m != em - 1) {
						if (base == 'W')
							base = 'B';
						else if (base == 'B')
							base = 'W';
					}
				}
			}

			if (ans > min(cnt1, cnt2))
				ans = min(cnt1, cnt2);
		}
	}

	printf("%d\n", ans);

	return 0;
}
