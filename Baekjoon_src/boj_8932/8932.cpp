#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		double p1, p2, p3, p4, p5, p6, p7;
		scanf("%lf %lf %lf %lf %lf %lf %lf", &p1, &p2, &p3, &p4, &p5, &p6, &p7);
		
		double sum = 
			int(9.23076 * pow(fabs(26.7-p1), 1.835)) +
			int(1.84523 * pow(fabs(75-p2), 1.348)) +
			int(56.0211 * pow(fabs(1.5-p3), 1.05)) +
			int(4.99087 * pow(fabs(42.5-p4), 1.81)) +
			int(0.188807 * pow(fabs(210-p5), 1.41)) +
			int(15.9803 * pow(fabs(3.8-p6), 1.04)) +
			int(0.11193 * pow(fabs(254-p7), 1.88));

		printf("%d\n", int(sum));
	}

	return 0;
}
