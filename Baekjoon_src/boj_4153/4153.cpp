#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	int a=1, b=1, c=1;

	while (true) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0)
			break;

		int max_v = max(a, max(b, c));
		int p_sum = 0;

		if (max_v == a)
			p_sum = b * b + c * c;
		else if (max_v == b)
			p_sum = a * a + c * c;
		else if (max_v == c)
			p_sum = a * a + b * b;

		if (p_sum == max_v * max_v)
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}
