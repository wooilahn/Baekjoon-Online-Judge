#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int x, y;
	scanf("%d\n%d", &x, &y);

	if (x > 0 && y > 0)
		printf("1\n");
	else if (x < 0 && y > 0)
		printf("2\n");
	else if (x < 0 && y < 0)
		printf("3\n");
	else if (x > 0 && y < 0)
		printf("4\n");

	return 0;
}
