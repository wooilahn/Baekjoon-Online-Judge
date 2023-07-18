#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> v;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	arr.push_back(d);
	arr.push_back(e);

	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);

	int ans = -1;

	do {
		int n1, n2, n3;
		int cnt = 0;

		for (int i = 0; i < v.size(); i++) {
			if (v[i]) {
				if (cnt == 0)
					n1 = arr[i];
				else if (cnt == 1)
					n2 = arr[i];
				else if (cnt == 2)
					n3 = arr[i];
				cnt++;
			}
		}

		if (ans == -1)
			ans = lcm(n1, lcm(n2, n3));
		else
			ans = min(ans, lcm(n1, lcm(n2, n3)));

	} while (next_permutation(v.begin(), v.end()));

	printf("%d\n", ans);

	return 0;
}
