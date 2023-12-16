#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 10000005
#include <stdio.h>
#include <math.h>

using namespace std;

long long A, B;
int prime[10000005] = { 0 };

void eratos() {
	prime[0] = 1;
	prime[1] = 1;

	for (int i = 2; i <= sqrt(MAX_N); i++){
		if (prime[i] == 1)
			continue;
		else {
			for (int k = (i * i); k < MAX_N; k += i)
				prime[k] = 1;
		}
	}
}

int main() {
	scanf("%lld %lld", &A, &B);
	eratos();

	long long R = 2;
	long long ans = 0;

	while (true) {
		long long nA = (long long)floor(pow((double)A, 1.0 / (double)R));
		long long nB = (long long)floor(pow((double)B, 1.0 / (double)R));

		for (long long i = nA; i <= (nB + 1); i++) {
			if (prime[i] == 0) {
				long long nn = (long long)pow((double)i, (double)R);

				if ((nn >= A) && (nn <= B))
					ans++;
			}
		}
		if ((nA == 1) && (nB == 1))
			break;
		else
			R++;
	}

	printf("%lld\n", ans);

	return 0;
}
