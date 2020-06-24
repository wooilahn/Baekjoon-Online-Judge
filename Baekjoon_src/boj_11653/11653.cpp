#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

bool eratos[10000005] = { 0 };

int N;

void prime() {
	eratos[0] = 1;
	eratos[1] = 1;

	for (int i = 2; i <= N; i++) {
		if (eratos[i] == 0) {
			for (int j = i + i; j <= N; j += i) {
				if(eratos[j] == 0)
					eratos[j] = 1;
			}
		}
	}

	return;
}

int main() {

	scanf("%d", &N);

	prime();

	for (int i = 2; i <= N; i++) {
		if (N % i == 0 && eratos[i]==0) {
			while (N % i== 0 && N!= 0) {
				printf("%d\n", i);
				N /= i;
			}
		}

		if (N == 1)
			break;
	}

	return 0;
}
