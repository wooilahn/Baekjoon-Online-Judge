#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>

using namespace std;

stack<long long> s;

int main() {

	long long K, tmp;
	scanf("%lld", &K);

	for (int i = 0; i < K; i++) {
		scanf("%lld", &tmp);

		if (tmp != 0)
			s.push(tmp);
		else if (tmp == 0)
			s.pop();
	}

	long long ans = 0;

	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}

	printf("%lld\n", ans);

	return 0;
}
