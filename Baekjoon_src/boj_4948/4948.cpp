#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int N;
bool eratos[300003] = { 0 };

void prime() {

	eratos[1] = true;

	for (int i = 2;i <= 123456;i++) {
		if (!eratos[i]) {
			for (int j = i * 2;j <= 2*123456;j += i)
				eratos[j] = true;
		}
	}
}

int main() {
	prime();

	while (true) {
		scanf("%d", &N);
		
		if (N == 0)
			break;

		int ans = 0;

		for (int i = N+1;i <= (2*N);i++) {
			if (!eratos[i])
				ans++;
		}

		printf("%d\n", ans);
	}

	return 0;
}
