#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> order;

int main() {
	int N, M, tmp;
	int ans = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0;i < N;i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	int tar = 3;

	for (int i = 0;i < tar;i++) 
		order.push_back(1);
	for (int i = 0;i < v.size() - tar; i++) 
		order.push_back(0);

	sort(order.begin(), order.end());

	do {
		int sum = 0;

		for (int i = 0; i < order.size(); i++) {
			if (order[i] == 1) 
				sum += v[i];
		}

		if (sum <= M) {
			if (sum > ans)
				ans = sum;
		}
	} while (next_permutation(order.begin(), order.end()));

	printf("%d\n", ans);
	return 0;
}
