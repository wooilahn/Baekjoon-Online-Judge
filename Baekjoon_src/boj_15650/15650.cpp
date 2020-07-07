#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
int N, M;
bool chk[10] = { 0 };
int  arr[10] = { 0 };


void func(int cur, int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for (int i = cur; i <= N; i++) {
		if (!chk[cnt]) {
			arr[cnt] = i;
			chk[cnt] = true;
			func(i + 1, cnt + 1);
			chk[cnt] = false;
		}
	}


	return;
}

int main() {
	scanf("%d %d", &N, &M);
	func(1, 0);
	return 0;
}
