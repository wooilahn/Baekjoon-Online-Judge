#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {

	int A, B, C;
	int max_v;

	scanf("%d %d %d", &A, &B, &C);
	max_v = max(A, max(B, C));

	if (max_v == A)
		printf("%d\n", max(B, C));
	else if (max_v == B)
		printf("%d\n", max(A, C));
	else if (max_v == C)
		printf("%d\n", max(A, B));

	return 0;
}
