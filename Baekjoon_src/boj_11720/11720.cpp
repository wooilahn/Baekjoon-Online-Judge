#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {

	char num[105] = { 0 };
	int N, ans = 0;
	scanf("%d\n%s", &N, num);

	for (int i = 0; i <  N; i++) {
		char tmp[2] = { 0 };
		strncpy(tmp, num + i, 1);
		ans += atoi(tmp);
	}

	printf("%d\n", ans);

	return 0;
}
