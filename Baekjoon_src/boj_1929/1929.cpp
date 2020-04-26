#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int M, N;
bool eratos[1000005] = { 0 };

void prime() {

	eratos[1] = true;

	for (int i = 2;i <= N / 2;i++) {
		if (!eratos[i]) {
			for (int j = i * 2;j <= N;j += i)
				eratos[j] = true;
		}
	}
}

int main() {

	scanf("%d %d", &M, &N);

	prime();

	for (int i = M;i <= N;i++) {
		if (!eratos[i])
			printf("%d\n", i);
	}


	return 0;
}
