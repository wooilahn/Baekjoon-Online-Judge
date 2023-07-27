#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> mv;

	for (int i = 0; i < n; i++) {
		vector<int> v;

		int P, L;
		scanf("%d %d", &P, &L);

		for (int k = 0; k < P; k++) {
			int mi;
			scanf("%d", &mi);
			v.push_back(-mi);
		}
		
		sort(v.begin(), v.end());

		if (P < L)
			mv.push_back(1);
		else
			mv.push_back(-v[L-1]);
	}

	sort(mv.begin(), mv.end());
	int ans = 0;
	int remi = m;

	for (int i = 0; i < mv.size(); i++) {
		if (remi >= mv[i]) {
			remi -= mv[i];
			ans++;
		}
		else
			break;
	}

	printf("%d\n", ans);

	return 0;
}
