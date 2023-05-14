#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long ll;

ll f_gcd(ll a, ll b) {

	ll c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main() {

	ll n;
	scanf("%lld", &n);

	ll a, b;

	while (n--) {
		scanf("%lld %lld", &a, &b);

		ll gcd = f_gcd(a, b);
		ll lcm = (a / gcd) * (b / gcd) * gcd;

		printf("%lld\n", lcm);
	}

	return 0;
}
