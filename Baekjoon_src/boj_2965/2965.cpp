#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	int AB = B - A - 1;
	int BC = C - B - 1;

	printf("%d\n", max(AB, BC));

	return 0;
}
