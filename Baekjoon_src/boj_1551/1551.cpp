#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <deque>

using namespace std;

int main() {

	int N, K;
	scanf("%d %d", &N, &K);

	deque<int> d;

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		getchar();
		d.push_back(num);
	}

	// K번 반복
	for (int i = 0; i < K; i++) {
		int d_size = d.size();

		for (int k = 1; k < d_size; k++) {
			d.push_back(d[k] - d[k-1]);
		}

		for (int k = 0; k < d_size; k++)
			d.pop_front();
	}

	
	for (int i = 0; i < d.size(); i++) {
		printf("%d", d[i]);

		if (i == d.size() - 1)
			printf("\n");
		else
			printf(",");

	}

	return 0;
}
