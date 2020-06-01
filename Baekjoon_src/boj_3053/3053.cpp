#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265358979323846
#include <stdio.h>

using namespace std;

int main() {

	double R;
	scanf("%lf", &R);
	printf("%lf\n%lf\n", PI*R*R, 2*R*R);

	return 0;
}
