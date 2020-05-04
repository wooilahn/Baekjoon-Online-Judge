#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

long long A, B, C;

long long power(long long n, long long k) {

	if (k == 0)
		return 1;

	long long tmp = power(n, k / 2);
	long long result = (tmp * tmp) % C;

	if (k % 2 == 1)
		result = (result * n) % C;

	return result;
}

int main() {

	scanf("%lld %lld %lld", &A, &B, &C);

	long long ans = power(A, B);
	printf("%lld\n", ans);

	return 0;
}
