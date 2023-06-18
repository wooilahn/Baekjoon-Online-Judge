#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
	int num;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int d1 = v[1] - v[0];
	int d2 = v[2] - v[1];

	if (d1 > d2) {
		printf("%d", v[0] + d1/2);
	}
	else if (d1 < d2) {
		printf("%d", v[1] + d2/2);
	}
	else if (d1 == d2) {
		printf("%d", v[2] + d1);
	}

	return 0;
}
