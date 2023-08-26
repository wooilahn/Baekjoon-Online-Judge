#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		printf("%d ", v[i]);
	printf("\n");

	return 0;
}
