#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int score[105] = { 0 };
priority_queue<int> q[105];

int main() {

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {

		for (int k = 0; k < M; k++) {
			int num;
			scanf("%d", &num);
			q[i].push(num);
		}
	}

	for (int k = 0; k < M; k++) {
		int max_v = q[0].top();

		for (int i = 1; i < N; i++) {
			if (max_v < q[i].top()) {
				max_v = q[i].top();
			}
		}

		for (int i = 0; i < N; i++) {
			if (max_v == q[i].top())
				score[i]++;
			q[i].pop();
		}
	}

	int ans = -1;

	for (int i = 0; i < N; i++) {
		if (ans < score[i])
			ans = score[i];
	}

	for (int i = 0; i < N; i++) {
		if (ans == score[i])
			printf("%d ", i+1);
	}
	printf("\n");

	return 0;
}
