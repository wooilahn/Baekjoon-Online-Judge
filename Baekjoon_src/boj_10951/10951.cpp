#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int a, b;

	while (scanf("%d %d", &a, &b) == 2) {
		printf("%d\n", a + b);
	}

	return 0;
}
