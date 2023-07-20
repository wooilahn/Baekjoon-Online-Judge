#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
	int N;
	scanf("%d", &N);

	int M, K;
	scanf("%d %d", &M, &K);

	int A;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A);
		v.push_back(A);
	}

	sort(v.begin(), v.end());

	int sum = M * K;
	int ans = 0;

	for (int i = v.size() - 1; i >= 0; i--) {
		sum -= v[i];
		ans++;

		if (sum <= 0) {
			printf("%d\n", ans);
			return 0;
		}
	}

	printf("STRESS\n");
	return 0;
}
