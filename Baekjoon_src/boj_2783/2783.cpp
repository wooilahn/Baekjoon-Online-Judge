#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	double X, Y, cost;
	scanf("%lf %lf", &X, &Y);

	cost = (X / Y) * 1000;

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		double Xi, Yi;
		scanf("%lf %lf", &Xi, &Yi);

		double costi;
		costi = (Xi / Yi) * 1000;

		if (cost > costi)
			cost = costi;
	}

	printf("%.2lf\n", cost);

	return 0;
}
