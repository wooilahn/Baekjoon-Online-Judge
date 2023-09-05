#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int mat1[105][105] = { 0 };
int mat2[105][105] = { 0 };

int main() {

	int N, M;
	scanf("%d %d", &N, &M);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &mat1[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &mat2[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", mat1[i][j] + mat2[i][j]);
		}
		printf("\n");
	}

	return 0;
}
