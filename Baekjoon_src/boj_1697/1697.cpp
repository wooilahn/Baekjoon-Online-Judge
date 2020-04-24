#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

bool check[100005] = { 0 };
int arr[100005] = { 0 };
int N, K;

queue<int> q;

void bfs() {

	if (N == K) {
		printf("0\n");
		return;
	}

	q.push(N);
	check[N] = true;
	
	while (!q.empty()) {
		int cur = q.front();
		int cnt = arr[cur];
		q.pop();

		int pos1 = cur + 1;
		int pos2 = cur - 1;
		int pos3 = cur * 2;

		if (pos1 == K || pos2 == K || pos3 == K) {
			printf("%d\n", cnt+1);
			break;
		}
	
		if (pos1 <= 100000 && !check[pos1]) {
			check[pos1] = true;
			q.push(pos1);
				
			if(arr[pos1] == 0 || arr[pos1] > cnt + 1)
				arr[pos1] = cnt + 1;
		}
			
		if (pos2 >= 0 && !check[pos2]) {
			check[pos2] = true;
			q.push(pos2);

			if (arr[pos2] == 0 || arr[pos2] > cnt + 1)
				arr[pos2] = cnt + 1;
		}

		if (pos3 <= 100000 && !check[pos3]) {
			check[pos3] = true;
			q.push(pos3);
			
			if (arr[pos3] == 0 || arr[pos3] > cnt + 1)
				arr[pos3] = cnt + 1;
		}

	}
}

int main() {
	scanf("%d %d", &N, &K);
	bfs();

	return 0;
}
