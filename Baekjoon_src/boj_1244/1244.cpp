#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;

int main() {
	int N, K;
	scanf("%d", &N);
	v.push_back(-1);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}

	scanf("%d", &K);
	int gd, nn;

	for (int i = 0; i < K; i++) {
		scanf("%d %d", &gd, &nn);

		if (gd == 1) { // man
			for (int t=nn; t<=N; t+=nn) {
				if (v[t] == 0)
					v[t] = 1;
				else if (v[t] == 1)
					v[t] = 0;
			}
		}
		else if (gd == 2) { // woman
			int dist = 0;

			while (true) {
				int s = nn - dist;
				int e = nn + dist;

				if (v[s] != v[e]) {
					dist--;
					break;
				}
				if (s == 1 || e == N)
					break;

				dist++;
			}

			for (int t = 0; t <= dist; t++) {
				if (t == 0) {
					if (v[nn] == 0)
						v[nn] = 1;
					else if (v[nn] == 1)
						v[nn] = 0;
				}
				else {
					if (v[nn + t] == 0)
						v[nn + t] = 1;
					else if (v[nn + t] == 1)
						v[nn + t] = 0;

					if (v[nn - t] == 0)
						v[nn - t] = 1;
					else if (v[nn - t] == 1)
						v[nn - t] = 0;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d", v[i]);

		if (i % 20 == 0)
			printf("\n");
		else
			printf(" ");
	}

	return 0;
}
