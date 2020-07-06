#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

bool check[10] = { 0 };
int arr[10] = { 0 };
int N, M;

void func(int cur, int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) 
			printf("%d ", arr[i]);

		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (check[i])
			continue;

		arr[cnt] = i;
		check[i] = true;
		func(1, cnt + 1);
		check[i] = false;
	}

	return;
}

int main() {

	scanf("%d %d", &N, &M);
	func(1, 0);

	return 0;
}
