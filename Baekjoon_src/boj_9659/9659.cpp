#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	long long n;
	scanf("%d", &n);

	if (n % 2 == 0)
		printf("CY\n");
	else
		printf("SK\n");

	return 0;
}
