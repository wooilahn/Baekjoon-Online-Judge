#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int d, n, s, p;
		scanf("%d %d %d %d", &d, &n, &s, &p);

		int dt = d + n * p;
		int st = n * s;
		
		if (dt < st)
			printf("parallelize\n");
		else if (dt == st)
			printf("does not matter\n");
		else if (dt > st)
			printf("do not parallelize\n");
	}

	return 0;
}
