#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	int hp, mp, at, df;
	int mhp, mmp, mat, mdf;

	while (T--) {
		scanf("%d %d %d %d %d %d %d %d", &hp, &mp, &at, &df, &mhp, &mmp, &mat, &mdf);

		int fhp = max(hp + mhp, 1);
		int fmp = max(mp + mmp, 1);
		int fat = max(at + mat, 0);
		int fdf = df + mdf;

		printf("%d\n", fhp+5*fmp+2*fat+2*fdf);
	}

	return 0;
}
