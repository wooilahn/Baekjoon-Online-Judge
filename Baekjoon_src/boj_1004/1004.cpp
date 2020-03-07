#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

double calculate_distance(double x1, double y1, double x2, double y2);

int main() {

	int T;
	scanf("%d", &T);

	while (T--) {
		int n, ans = 0;
		double x1, y1, x2, y2;
		double cx, cy, r;
		double dist1, dist2;

		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		scanf("%d", &n);

		for (int i = 0;i < n;i++) {
			scanf("%lf %lf %lf", &cx, &cy, &r);

			dist1 = calculate_distance(x1, y1, cx, cy);
			dist2 = calculate_distance(x2, y2, cx, cy);

			if (dist1 < r && dist2 < r)
				continue;
			else if (dist1 > r && dist2 > r)
				continue;
			else
				ans++;
		}

		printf("%d\n", ans);
	}

	return 0;
}

double calculate_distance(double x1, double y1, double x2, double y2) {
	double distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	return distance;
}
