#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {

	long long S, N;
	scanf("%lld", &S);

	N = (long long)((long long)(-1 + sqrt(1+8*S)) / 2);
	printf("%lld\n", N);

	return 0;
}
