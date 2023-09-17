#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;

int main() {
	int N, NS, P; 
	scanf("%d %d %d", &N, &NS, &P);

	if (N == 0) {
		printf("1\n");
		return 0;
	}

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	int ans = -1;

	int curIdx = v.size() - 1;
	int eqCnt = 0;

	while (v[curIdx] >= NS) {
		if (v[curIdx] == NS)
			eqCnt++;
		curIdx--;

		if (curIdx == -1)
			break;
	}

	int totalCnt = v.size() - (curIdx+1) + 1;

	if (totalCnt > P)
		ans = -1;
	else
		ans = v.size() - (curIdx+1 + eqCnt) + 1;

	printf("%d\n", ans);

	return 0;
}
