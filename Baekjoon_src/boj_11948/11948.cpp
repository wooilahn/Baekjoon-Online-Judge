#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int A, B, C, D, E, F;
	scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);

	int smin = min(min(A, B), min(C, D));
	int smin2 = min(E, F);
	int ans = A + B + C + D + E + F - smin - smin2;

	printf("%d\n", ans);

	return 0;
}
