#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;

int gcd(int g1, int g2) {
	while (g2 != 0) {
		int tmp = g1 % g2;
		g1 = g2;
		g2 = tmp;
	}

	return g1;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}

	int cg = gcd(v[1]-v[0], v[2]-v[1]);

	for (int i = 3; i < N; i++) {
		cg = gcd(cg, v[i]-v[i-1]);
	}

	int ans = 0;

	for (int i = 1; i < N; i++) {
		int d = v[i] - v[i-1];

		ans += (d/cg) - 1;
	}

	printf("%d\n", ans);
	return 0;
}
