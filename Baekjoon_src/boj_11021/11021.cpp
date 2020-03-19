#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d\n", i, A + B);
	}

	return 0;
}
