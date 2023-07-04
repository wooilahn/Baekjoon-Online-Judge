#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;

int main() {
	int N, num;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}

	int idx = N - 1;

	while (true) {
		if (idx == 0) {
			printf("-1\n");
			return 0;
		}

		if (v[idx] > v[idx-1])
			idx--;
		else
			break;
	}

	int idx2 = N - 1;

	while (true) {
		if (v[idx2] > v[idx - 1])
			idx2--;
		else
			break;
	}

	int tmp = v[idx - 1];
	v[idx - 1] = v[idx2];
	v[idx2] = tmp;

	for (int i = 0; i < idx; i++)
		printf("%d ", v[i]);

	for (int i = N - 1; i >= idx; i--)
		printf("%d ", v[i]);

	printf("\n");

	return 0;
}
