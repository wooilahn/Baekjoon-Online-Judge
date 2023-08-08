#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
	int A, B;
	scanf("%d %d", &A, &B);

	int Ap, Bp, Aq, Bq;

	Ap = A / 4;
	Aq = A % 4;

	if (Aq == 0) {
		Ap--;
		Aq = 4;
	}

	Bp = B / 4;
	Bq = B % 4;

	if (Bq == 0) {
		Bp--;
		Bq = 4;
	}

	printf("%d\n", abs(Ap - Bp) + abs(Aq - Bq));
	return 0;
}
