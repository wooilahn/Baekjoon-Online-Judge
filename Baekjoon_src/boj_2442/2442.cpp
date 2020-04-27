#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N;i++) {

		for (int j = N - i;j > 0;j--) 
			printf(" ");

		for (int j = 1;j <= 2 * i - 1;j++)
			printf("*");

		printf("\n");
	}


	return 0;
}
