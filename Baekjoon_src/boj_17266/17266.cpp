#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int bridge[100005] = { 0 };
vector<int> v;


int main() {
	int N, M, num;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}

	int ans = max(v[0], N - v[M-1]);
	
	for (int i = 0; i < M-1; i++) {
		int dist = (v[i+1] - v[i]) / 2;
		int qr   = (v[i+1] - v[i]) % 2;

		ans = max(ans, dist+qr);
	}

	printf("%d\n", ans);
	return 0;
}
