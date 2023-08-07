#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> v;

int main() {
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);

	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);

	arr.push_back(A);
	arr.push_back(B);
	arr.push_back(C);
	arr.push_back(D);

	int ans = 0;

	do {
		int p1 = 0;
		int p2 = 0;
		int q1 = 0;
		int q2 = 0;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 1) {
				if (p1 == 0)
					p1 = arr[i];
				else
					p2 = arr[i];
			}
			else if (v[i] == 0) {
				if (q1 == 0)
					q1 = arr[i];
				else
					q2 = arr[i];
			}

			int sd = min(p1, p2) * min(q1, q2);
			ans = max(ans, sd);
		}
	} while (next_permutation(v.begin(), v.end()));

	printf("%d\n", ans);
	return 0;
}
