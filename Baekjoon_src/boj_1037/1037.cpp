#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int arr[55] = { 0 };

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	printf("%d", arr[0] * arr[n - 1]);
}
