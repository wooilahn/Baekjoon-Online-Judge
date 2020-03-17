#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int score;
	scanf("%d", &score);

	if (90 <= score && score <= 100)
		printf("A\n");
	else if (80 <= score && score < 90)
		printf("B\n");
	else if (70 <= score && score < 80)
		printf("C\n");
	else if (60 <= score && score < 70)
		printf("D\n");
	else
		printf("F\n");

	return 0;
}
