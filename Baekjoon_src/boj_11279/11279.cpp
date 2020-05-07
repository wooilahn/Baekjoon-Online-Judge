#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main() {

	int N, x;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &x);

		if (x == 0) {
			if (pq.empty()) {
				printf("0\n");
				continue;
			}
			printf("%d\n", pq.top());
			pq.pop();
		}

		pq.push(x);
	}

	return 0;
}
