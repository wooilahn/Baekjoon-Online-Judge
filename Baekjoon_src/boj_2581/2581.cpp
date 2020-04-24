#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

bool arr[10002] = { 0 };
int M, N;
int sum, min_prime;

void prime() {

	arr[1] = true;

	for (int i = 2; i <= N/2; i++) {
		if (!arr[i]) {
			for (int j = i + i; j <= N; j += i)
				arr[j] = true;
		}
	}

	for (int i = M; i <= N; i++) {
		if (!arr[i]) {
			if (min_prime < 0)
				min_prime = i;

			sum += i;
		}
	}

	if(min_prime < 0)
		printf("%d\n", min_prime);
	else
		printf("%d\n%d", sum, min_prime);
}

int main() {
	scanf("%d %d", &M, &N);
	sum = 0, min_prime = -1;
	prime();

	return 0;
}
