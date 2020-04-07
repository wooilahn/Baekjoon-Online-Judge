#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {

	long long A, B, V;
	long long ans = 0;

	scanf("%lld %lld %lld", &A, &B, &V);
	ans = ((long long)ceil((double)(V - A) / (A - B))) + 1;
	printf("%lld\n", ans);

	return 0; 
}
