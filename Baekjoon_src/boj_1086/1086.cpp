#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long ll;

int N, K;
ll dp[1 << 16][105];
char str[20][55] = { 0 };
int arr[20], lens[20];
int pw[55];

ll func(int bits, int md) {
	ll& res = dp[bits][md];

	if (res != -1) {
		return res;
	}

	if (bits+1 == 1<<N) {
		if (md)
			return res = 0;
		else
			return res = 1;
	}

	res = 0;

	for (int i = 0; i < N; i++) {
		if (!(bits & (1<<i))) {
			int t = md * pw[lens[i]] + arr[i];
			res += func((bits | (1 << i)), t % K);
		}
	}

	return res;
}

ll gcd(ll a, ll b) {
	ll tmp, n;

	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;;
	}

	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}

	return a;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) 
		scanf("%s", str[i]);

	scanf("%d", &K);

	for (int i = 0; i < N; i++) {
		int len = strlen(str[i]);
		lens[i] = len;

		int t = 0;

		for (int j = 0; j < len; j++) {
			int c = str[i][j];

			t *= 10;
			t %= K;
			t += c - '0';
			t %= K;
		}

		arr[i] = t;
	}

	pw[0] = 1 % K;
	for (int i = 1; i < 55; i++) 
		pw[i] = (pw[i-1] * 10) % K;
	
	memset(dp, -1, sizeof(dp));
	ll p = func(0, 0), q = 1;

	if (p == 0) {
		printf("0/1\n");
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		q *= i;
	}

	ll g = gcd(p, q);
	p /= g, q /= g;
	printf("%lld/%lld\n", p, q);
	
	return 0;
}
