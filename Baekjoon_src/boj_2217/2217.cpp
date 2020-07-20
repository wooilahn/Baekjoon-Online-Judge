#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> v;

int main() {

	long long N, tmp;
	scanf("%lld", &N);

	for (long long i = 0; i < N; i++) {
		scanf("%lld", &tmp);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	long long cnt = 1, ans = -1;

	for (int i = 1; i <= N; i++) {
		long long tmp_ans = v.at(N - i) * i;
		ans = max(ans, tmp_ans);
	}

	printf("%lld\n", ans);
	return 0;
}
