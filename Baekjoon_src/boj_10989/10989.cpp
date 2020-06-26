#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int arr[10005] = { 0 };

int main() {

	int N, tmp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		while (arr[i] > 0) {
			printf("%d\n", i);
			arr[i]--;
		}
	}

	return 0;
}
