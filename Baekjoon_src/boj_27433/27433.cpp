#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

long long factorial(long long num) {
	if (num == 0 || num == 1)
		return 1;
	else
		return num * factorial(num - 1);
}

int main() {

	long long n;
	scanf("%lld", &n);

	printf("%lld\n", factorial(n));

	return 0;
}

