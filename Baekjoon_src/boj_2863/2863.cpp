#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	double A, B, C, D;
	scanf("%lf %lf %lf %lf", &A, &B, &C, &D);

	double q1, q2, q3, q4, qm;

	q1 = A/C + B/D;
	q2 = C/D + A/B;
	q3 = D/B + C/A;
	q4 = B/A + D/C;

	qm = max(max(q1, q2), max(q3, q4));

	if (qm == q1) {
		printf("0\n");
	}
	else if (qm == q2) {
		printf("1\n");
	}
	else if (qm == q3) {
		printf("2\n");
	}
	else if (qm == q4) {
		printf("3\n");
	}

	return 0;
}



