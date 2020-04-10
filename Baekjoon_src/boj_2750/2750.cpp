#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int arr[1002] = { 0 };

int main() {

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++) {
		int target = 1001;
		int idx = -1;

		for (int j = i; j < N; j++) {
			if (target > arr[j]) {
				target = arr[j];
				idx = j;
			}
		}

		int tmp = arr[i];
		arr[i] = target;
		arr[idx] = tmp;
	}

	for (int i = 0; i < N; i++) 
		printf("%d\n", arr[i]);
	

	return 0;
}
