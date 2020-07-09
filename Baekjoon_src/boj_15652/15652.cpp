#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int N, M;
int arr[10] = { 0 };

void func(int cnt) {
	
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (cnt != 0 && arr[cnt-1] > i) {
			continue;
		}

		arr[cnt] = i;
		func(cnt + 1);
	}

	return;
}

int main() {

	scanf("%d %d", &N, &M);
	func(0);

	return 0;
}
