#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);

	int space, star;

	for (int i = N; i >= 1; i--) {
		space = N - i, star = 2*i - 1;

		for (int k = 0; k < space; k++)
			printf(" ");

		for (int k = 0; k < star; k++)
			printf("*");

		printf("\n");
	}

	for (int i = 2; i <= N; i++) {
		space = N - i, star = 2*i - 1;

		for (int k = 0; k < space; k++)
			printf(" ");

		for (int k = 0; k < star; k++)
			printf("*");

		printf("\n");
	}

	return 0;
}
