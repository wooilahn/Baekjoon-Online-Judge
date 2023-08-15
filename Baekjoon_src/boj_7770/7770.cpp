#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int block = 0;
	int h = 0;

	while (true) {
		block += 2*h*h + 2*h + 1;

		if (block > N)
			break;

		h++;
	}

	printf("%d\n", h);
	return 0;
}
