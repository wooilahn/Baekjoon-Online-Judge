#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int arr[43] = { 0 };

int main() {

	int tmp, ans = 0;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &tmp);
		arr[tmp % 42]++;
	}

	for (int i = 0; i < 42; i++) {
		if (arr[i])
			ans++;
	}

	printf("%d\n", ans);


	return 0;
}
