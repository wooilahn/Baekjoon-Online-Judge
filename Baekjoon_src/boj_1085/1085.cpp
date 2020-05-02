#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int x, y, w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d\n", min(min(x, y), min((w - x), (h - y))));

	return 0;
}
