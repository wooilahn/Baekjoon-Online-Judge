#define _CRT_SECURE_NO_WARNINGS
#define TIME_MAX 987654321;
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;

int dp[100005][2] = { 0 }; // dp[i][0]: time, dp[i][1]: previous point
queue<int> q;
stack<int> s;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < 100002; i++) {
		dp[i][0] = TIME_MAX;
		dp[i][1] = -1;
	}

	dp[N][0] = dp[N][1] = 0;
	q.push(N);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == K)
			break;

		// case 1: X-1
		if (cur - 1 >= 0) {
			if (dp[cur][0] + 1 < dp[cur-1][0]) {
				dp[cur-1][0] = dp[cur][0] + 1; // update time
				dp[cur-1][1] = cur;            // update previous point
				q.push(cur-1);
			}
		}

		// case 2: X+1
		if (cur + 1 <= 100000) {
			if (dp[cur][0] + 1 < dp[cur+1][0]) {
				dp[cur+1][0] = dp[cur][0] + 1; // update time
				dp[cur+1][1] = cur;            // update previous point
				q.push(cur+1);
			}
		}

		// case 3: X*2
		if (cur * 2 <= 100000) {
			if (dp[cur][0] + 1 < dp[cur*2][0]) {
				dp[cur*2][0] = dp[cur][0] + 1; // update time
				dp[cur*2][1] = cur;            // update previous point
				q.push(cur*2);
			}
		}
	}

	printf("%d\n", dp[K][0]);

	int t = K;

	while (t != N) {
		s.push(t);
		t = dp[t][1];
	}
	s.push(N);

	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
	printf("\n");

	return 0;
}
