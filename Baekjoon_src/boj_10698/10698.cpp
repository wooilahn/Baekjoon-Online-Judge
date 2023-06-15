#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int X, Y, Z;
	char O;

	for(int i=1; i<=N; i++) {
		scanf("%d %c %d = %d", &X, &O, &Y, &Z);

		printf("Case %d: ", i);
		int target = 0;

		switch (O) {
		case '+':
			target = X + Y;
			break;
		case '-':
			target = X - Y;
			break;
		default:
			break;
		}

		if (target == Z)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
