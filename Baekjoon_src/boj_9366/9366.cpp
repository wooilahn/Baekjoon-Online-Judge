#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	for(int i=1; i<=T; i++) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		printf("Case #%d: ", i);

		if (A + B <= C || B + C <= A || A + C <= B) {
			printf("invalid!\n");
			continue;
		}

		int cnt = 0;

		if (A == B)
			cnt++;
		if (B == C)
			cnt++;
		if (A == C)
			cnt++;

		switch (cnt) {
		case 0:
			printf("scalene\n");
			break;
		case 1:
			printf("isosceles\n");
			break;
		case 3:
			printf("equilateral\n");
			break;
		default:
			break;
		}
	}

	return 0;
}
