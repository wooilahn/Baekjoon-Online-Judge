#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char num1[5] = { 0 }, num2[5] = { 0 };

void swap(char* num) {
	char tmp = num[0];
	num[0] = num[2];
	num[2] = tmp;

	return;
}

int main() {
	scanf("%s %s", num1, num2);

	swap(num1);
	swap(num2);

	int n1, n2;
	n1 = atoi(num1);
	n2 = atoi(num2);

	printf("%d", n1 > n2 ? n1 : n2);

	return 0;
}
