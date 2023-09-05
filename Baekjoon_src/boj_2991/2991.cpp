#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int A, B, C, D;
	int P, M, N;

	scanf("%d %d %d %d", &A, &B, &C, &D);
	scanf("%d %d %d", &P, &M, &N);

	int cntP = 0;
	int cntM = 0;
	int cntN = 0;

	int curP1 = 0;
	int curP2 = 0;

	int curM1 = 0;
	int curM2 = 0;

	int curN1 = 0;
	int curN2 = 0;

	while (true) {
		curP1 += A;

		if (curP1 >= P) {
			cntP++;
			break;
		}

		curP1 += B;

		if (curP1 >= P)
			break;
	}

	while (true) {
		curP2 += C;

		if (curP2 >= P) {
			cntP++;
			break;
		}

		curP2 += D;

		if (curP2 >= P)
			break;
	}

	while (true) {
		curM1 += A;

		if (curM1 >= M) {
			cntM++;
			break;
		}

		curM1 += B;

		if (curM1 >= M)
			break;
	}

	while (true) {
		curM2 += C;

		if (curM2 >= M) {
			cntM++;
			break;
		}

		curM2 += D;

		if (curM2 >= M)
			break;
	}

	while (true) {
		curN1 += A;

		if (curN1 >= N) {
			cntN++;
			break;
		}

		curN1 += B;

		if (curN1 >= N)
			break;
	}

	while (true) {
		curN2 += C;

		if (curN2 >= N) {
			cntN++;
			break;
		}

		curN2 += D;

		if (curN2 >= N)
			break;
	}

	printf("%d\n%d\n%d\n", cntP, cntM, cntN);

	return 0;
}
