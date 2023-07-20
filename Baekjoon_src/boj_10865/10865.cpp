#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int cnt[100005] = { 0 };

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int A, B;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);
		cnt[A]++;
		cnt[B]++;
	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n", cnt[i]);
	}

	return 0;
}
