#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	double A, B;

	scanf("%lf %lf", &A, &B);
	printf("%.010lf", A / B);

	return 0;
}
