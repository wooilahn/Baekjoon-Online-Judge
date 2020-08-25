#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
vector<int> v;

int dp[1005] = { 0 };
int tr[1005] = { 0 };

int solve(int n) {
	return 1;
}

void print(int n) {

	vector<int> pv;

	while (true) {
		pv.push_back(v[n]);

		if (tr[n] == -1)
			break;

		n = tr[n];
	}

	for (int i = pv.size() - 1; i >= 0; i--) 
		printf("%d ", pv.at(i));
	
	printf("\n");

	return;
}

int main() {
	int N, tmp;
	scanf("%d", &N);
	memset(tr, -1, sizeof(tr));

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	dp[0] = 1;

	for (int i = 0; i < N; i++) {
		int tmp = 1;

		for (int k = i - 1; k >= 0; k--) {
			if (v[i] > v[k]) {
				if (tmp <= dp[k]) {
					tmp = dp[i] = dp[k] + 1;
					tr[i] = k;
				}
			}
		}

		if (tmp == 1) {
			dp[i] = tmp;
			tr[i] = -1;
		}
	}

	int ans = -1, end_n = -1;

	for (int i = 0; i < N; i++) {
		if (ans < dp[i]) {
			ans = dp[i];
			end_n = i;
		}
	}

	printf("%d\n", ans);
	print(end_n);

	return 0;
}
