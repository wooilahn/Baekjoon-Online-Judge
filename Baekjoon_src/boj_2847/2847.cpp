#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<int> v;

	for(int i=0; i<N; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}


	int ans = 0;

	for (int i = N-1; i > 0; i--) {
		if (v[i-1] >= v[i]) {
			ans += v[i-1] - v[i] + 1;
			v[i - 1] = v[i] - 1;
		}
	}

	printf("%d\n", ans);

	return 0;
}
