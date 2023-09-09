#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
	int L, N, num;
	scanf("%d", &L);

	for (int i = 0; i < L; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	scanf("%d", &N);

	sort(v.begin(), v.end());

	int lower_b = -1;
	int upper_b = -1;
	int ans = 0;

	for (int i = 0; i < L; i++) {
		if (v[i] > N) {
			upper_b = v[i];
			lower_b = v[i-1];
			break;
		}
	}

	if (upper_b == -1) {
		upper_b = 1001;
		lower_b = v[v.size()-1];
	}

	for (int i = lower_b + 1; i <= N; i++) {
		ans += min(upper_b-i-1, upper_b-N);
	}

	printf("%d\n", ans);

	return 0;
}
