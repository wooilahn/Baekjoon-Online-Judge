#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {

	int test;
	float x1, y1, r1, x2, y2, r2;
	float distance, sum_radius, diff_radius;

	scanf("%d", &test);

	while (test--) {
		scanf("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);

		if (x1 == x2 && y1 == y2 && r1 == r2) {
			printf("-1\n");
			continue;
		}

		distance = sqrtf(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
		sum_radius = r1 + r2;
		diff_radius = fabsf(r1 - r2);

		if (diff_radius < distance && distance < sum_radius)
			printf("2\n");
		else if (sum_radius == distance || diff_radius == distance)
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}
