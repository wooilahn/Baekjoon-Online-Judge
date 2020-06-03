#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int factorial(int n) {
	if (n == 1 || n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

int main() {

	int N;
	scanf("%d", &N);

	printf("%d\n", factorial(N));

	return 0;
}


