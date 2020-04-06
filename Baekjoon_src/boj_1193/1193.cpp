#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <cmath>

using namespace std;

int main() {

	int X;
	int nume = 0, deno = 0; // numerator, denominator
	scanf("%d", &X);

	int N = (int)ceil(((-1 + sqrt(1 + 8 * X)) / 2));


	int sum = (N * (N + 1)) / 2;

	if (N % 2 == 1) {
		nume = 1, deno = N;

		while (true) {
			if (sum == X) {
				printf("%d/%d\n", nume, deno);
				break;
			}

			sum--;
			nume++;
			deno--;
		}
	}
	else if (N % 2 == 0) {
		nume = N, deno = 1;

		while (true) {
			if (sum == X) {
				printf("%d/%d\n", nume, deno);
				break;
			}

			sum--;
			nume--;
			deno++;
		}
	}


	return 0;
}
