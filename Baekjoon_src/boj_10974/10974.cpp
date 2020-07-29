#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<int> v(N);

	for (int i = 0; i < N; i++)
		v.at(i) = i + 1;

	do {
		for (int i = 0; i < N; i++)
			printf("%d ", v.at(i));
		printf("\n");
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}
