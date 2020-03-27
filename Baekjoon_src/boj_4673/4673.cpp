#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

bool check[10005] = { 0 };

void d(int n);

int main() {

	d(1);

	for (int i = 1; i < 10000; i++) {
		if (!check[i])
			printf("%d\n", i);
	}

	return 0;
}

void d(int n) {

	if (n >= 10000)
		return;

	int target = 0, tmp = n;

	while (tmp != 0) {
		target += tmp % 10;
		tmp /= 10;
	}

	target += n;

	if(target < 10000)
		check[target] = true;

	d(n + 1);
	return;
}
