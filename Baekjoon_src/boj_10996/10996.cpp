#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);

	int upper_star, lower_star;

	if (N % 2 == 1) { // odd number
		upper_star = (N / 2) + 1;
		lower_star = (N / 2);
	}
	else if (N % 2 == 0)  // even number
		upper_star = lower_star = (N / 2);
	
	for (int i = 1; i <= N*2; i++) {
		if (i % 2 == 1) { // odd number
			for (int i = 1; i <= upper_star; i++) {
				printf("*");

				if (i != upper_star)
					printf(" ");
			}
		}
		else if (i % 2 == 0) { // even number
			for (int i = 1; i <= lower_star; i++) 
				printf(" *");
		}

		if (i != N*2)
			printf("\n");
	}

	return 0;
}
