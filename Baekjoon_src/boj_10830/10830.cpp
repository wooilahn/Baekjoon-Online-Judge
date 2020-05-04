#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;
typedef long long lld;

lld N, B;
lld arr[6][6] = { 0 };

vector<vector<lld>> power(lld k);

int main() {

	scanf("%lld %lld", &N, &B);

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			scanf("%lld", &arr[i][j]);

	vector<vector<lld>> ans(N, vector<lld>(N));
	ans = power(B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%lld ", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}

vector<vector<lld>> power(lld k) {

	vector<vector<lld>> result(N, vector<lld>(N));
	vector<vector<lld>> tmp(N, vector<lld>(N));

	if (k == 1) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				result[i][j] = arr[i][j] % 1000;
			}
		}

		return result;
	}

	if (k % 2 == 0) { // even number
		tmp = power(k / 2);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++)
					result[i][j] += tmp[i][k] * tmp[k][j];

				result[i][j] %= 1000;
			}
		}
	}
	else if (k % 2 == 1) { // odd number
		tmp = power(k - 1);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++)
					result[i][j] += tmp[i][k] * arr[k][j];

				result[i][j] %= 1000;
			}
		}
	}

	return result;
}
