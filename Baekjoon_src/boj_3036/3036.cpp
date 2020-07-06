#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;
vector<int> ring;

int gcd(int a, int b) {
	int tmp, n;

	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}

	return a;
}

int main() {
	int N, tmp, g;
	scanf("%d", &N);

	for (int i = 0;i < N;i++) {
		scanf("%d", &tmp);
		ring.push_back(tmp);
	}

	for (int i = 1;i < N;i++) {
		g = gcd(ring.at(0), ring.at(i));
		printf("%d/%d\n", ring.at(0)/g, ring.at(i)/g);
	}

	return 0;
}
