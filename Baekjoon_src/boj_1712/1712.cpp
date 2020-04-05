#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	if (B >= C)
		printf("-1\n");
	else
		printf("%d\n", (A / (C-B)) + 1);


	return 0;
}
