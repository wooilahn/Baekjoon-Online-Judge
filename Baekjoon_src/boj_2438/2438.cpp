#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= i; k++)
			printf("*");
		printf("\n");
	}

	return 0;
}
