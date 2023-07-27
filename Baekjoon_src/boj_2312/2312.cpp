#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int arr[100005] = { 0 };

void eratos() {
	for (int i = 2; i <= 50000; i++) {
		if (!arr[i]) {
			for (int j=i+i; j<=100001; j+=i)
				arr[j] = 1;
		}
	}

	return;
}

int main() {
	int T, N;
	scanf("%d", &T);

	arr[0] = 1;
	arr[1] = 1;
	eratos();

	while (T--) {
		scanf("%d", &N);
		int num = N;
		int k = 0;

		while (true) {
			k++;

			for (int q = k; q <= N; q++) {
				if (!arr[q]) {
					k = q;
					break;
				}
			}

			int cnt = 0;

			while (num % k == 0) {
				num /= k;
				cnt++;
			}

			if(cnt > 0)
				printf("%d %d\n", k, cnt);
			
			if (num == 1)
				break;
		}
	}

	return 0;
}
