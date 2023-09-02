#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int check[100] = { 0 };

int main() {

	int s1, s2, s3;
	scanf("%d %d %d", &s1, &s2, &s3);

	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			for (int k = 1; k <= s3; k++) {
				check[i+j+k]++;
			}
		}
	}

	int maxIdx = 0;
	int maxVal = 0;

	for (int i = 1; i <= s1 + s2 + s3; i++) {
		if (maxVal < check[i]) {
			maxVal = check[i];
			maxIdx = i;
		}
	}

	printf("%d\n", maxIdx);

	return 0;
}
