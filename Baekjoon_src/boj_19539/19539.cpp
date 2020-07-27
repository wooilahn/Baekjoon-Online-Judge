#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int N, tmp, sum = 0, div = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		sum += tmp;
		div += (tmp/2);
	}

	if (sum % 3 != 0)
		printf("NO\n");
	else if (sum / 3 <= div)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
