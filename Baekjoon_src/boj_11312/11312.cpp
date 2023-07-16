#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		double A, B;
		scanf("%lf %lf", &A, &B);

		double As = A * A / 2;
		double Bs = B * B / 2;

		printf("%.0lf\n", (double)(As/Bs));
	}



	return 0;
}
