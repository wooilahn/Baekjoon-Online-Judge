#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int arr[10] = { 0 };

int main() {

	int A, B, C, target;
	scanf("%d %d %d", &A, &B, &C);

	target = A * B * C;

	while (target != 0) {
		arr[target % 10]++;
		target /= 10;
	}

	for (int i = 0;i < 10;i++)
		printf("%d\n", arr[i]);


	return 0;
}
