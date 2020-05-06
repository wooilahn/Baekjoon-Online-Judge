#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

typedef pair<int, int> p_e;
priority_queue<p_e, vector<p_e>, greater<p_e>> p_q;

int main() {
	int N, x;
	p_e target;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &x);

		if (x == 0) {
			if (p_q.empty())
				printf("0\n");
			else {
				target = p_q.top();
				p_q.pop();

				printf("%d\n", target.second);
			}
		}
		else
			p_q.push(make_pair(abs(x), x));
	}

	return 0;
}
