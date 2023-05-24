#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	long long N;
	scanf("%lld", &N);

	long long ans = 5 + ((N*(N+1)/2)-1)*3 + (N-1);
	printf("%lld\n", ans % 45678);

	return 0;
}
