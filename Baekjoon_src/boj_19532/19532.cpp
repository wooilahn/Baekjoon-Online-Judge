#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int x, y;
	double a, b, c, d, e, f;
	scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);

	x = (int)((e*c - b*f) / (a*e - b*d));
	y = (int)((a*f - c*d) / (a*e - b*d));

	printf("%d %d\n", x, y);

	return 0;
}
