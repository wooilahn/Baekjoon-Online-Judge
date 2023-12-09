#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {


	while (b != 0) {
		ll tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

int main() {
	ll T, n;
	scanf("%lld", &T);

	while (T--) {
		scanf("%lld", &n);
		vector<ll> v;
		ll ans = 0;

		for (ll i = 0; i < n; i++) {
			ll num;
			scanf("%lld", &num);
			v.push_back(num);
		}

		for (ll i = 0; i < n-1; i++) {
			for (ll j = i+1; j < n; j++) {
				ans += gcd(v[i], v[j]);
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}
