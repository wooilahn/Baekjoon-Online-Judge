#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	int a, b, c;
	int max_v, min_v;

	while (true) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0)
			break;

		max_v = max(a, max(b, c));

		if (a + b + c - max_v <= max_v) {
			printf("Invalid\n");
			continue;
		}

		if (a == b && b == c && c == a)
			printf("Equilateral\n");
		else if (a != b && b != c && c != a)
			printf("Scalene\n");
		else
			printf("Isosceles\n");
	}
	return 0;
}
