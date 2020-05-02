#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

bool eratos[10005] = { 0 };

void prime() {

	eratos[1] = 1;

	for (int i = 2;i <= 5002;i++) {
		if (eratos[i] == 0) {
			for (int j = i * 2;j <= 10004;j += i)
				eratos[j] = 1;
		}
	}
}

int main() {

	int T, n;
	scanf("%d", &T);

	prime();

	while (T--) {
		scanf("%d", &n);
		int a, b;

		for (int i = 2;i <= n/2; i++) {
			if (eratos[i] == 0 && eratos[n-i] == 0) {
				a = i;
				b = n - i;
			}
		}

		printf("%d %d\n", a, b);
	}

	return 0;
}
