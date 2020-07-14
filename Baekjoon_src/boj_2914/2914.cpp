#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int A, I;
	scanf("%d %d", &A, &I);

	printf("%d\n", (A * (I - 1)) + 1);

	return 0;
}
