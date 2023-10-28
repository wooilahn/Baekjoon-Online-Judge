#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int dp[250005] = { 0 };

int main() {
	int N, X, num;
	scanf("%d %d", &N, &X);

	v.push_back(0);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}

	dp[0] = 0;
	for (int i = 1; i <= N; i++)
		dp[i] = dp[i-1] + v[i];

	int ansv = 0;
	int ansn = 0;

	for (int i = 0; i <= N-X; i++) {
		int curv = dp[i+X] - dp[i];

		if (ansv == curv)
			ansn++;
		else if (ansv < curv) {
			ansv = curv;
			ansn = 1;
		}
	}

	if (ansv == 0)
		printf("SAD\n");
	else
		printf("%d\n%d\n", ansv, ansn);

	return 0;
}
