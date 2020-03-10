#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int T;
	scanf("%d", &T);

	while (T--) {
		int a, b;
		scanf("%d %d", &a, &b);

		int target = a;

		for (int i = 1; i < b; i++) {
		target = (target * a) % 10;
	}
		
		if (target == 0)
			printf("10\n");
		else
			printf("%d\n", target);
	}

	return 0;
}
