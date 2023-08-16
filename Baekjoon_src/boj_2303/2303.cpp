#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[1005];
vector<int> ans;

int main() {
	int N;
	scanf("%d", &N);

	ans.push_back(0);

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < 5; k++) {
			int num;
			scanf("%d", &num);
			v[i].push_back(num);
		}

		vector<int> arr;
		ans.push_back(0);
		arr.push_back(0);
		arr.push_back(0);
		arr.push_back(1);
		arr.push_back(1);
		arr.push_back(1);

		do {
			int sum = 0;

			for (int k = 0; k < 5; k++) {
				if (arr[k]) {
					sum += v[i][k];
				}
			}

			sum %= 10;
			if (sum > ans[i+1])
				ans[i+1] = sum;
		} while (next_permutation(arr.begin(), arr.end()));
	}

	int ans_n = 1;
	int ans_v = ans[1];

	for (int k = 2; k <= N; k++) {
		if (ans_v <= ans[k]) {
			ans_n = k;
			ans_v = ans[k];
		}
	}

	printf("%d\n", ans_n);

	return 0;
}
