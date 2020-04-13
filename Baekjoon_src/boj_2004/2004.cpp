#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

pair<ll, ll> func(ll num);

int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);

	vector<pair <ll, ll>> v(3);

	v[0] = func(n);
	v[1] = func(m);
	v[2] = func(n - m);

	ll two_n = v[0].first - (v[1].first + v[2].first);
	ll five_n = v[0].second - (v[1].second + v[2].second);
	printf("%lld\n", min(two_n, five_n));

	return 0;
}

pair<ll, ll> func(ll num) {

	ll two_num = 0, five_num = 0;

	for (ll i = 2; i <= num; i *= 2)
		two_num += num / i;

	for (ll i = 5; i <= num; i *= 5)
		five_num += num / i;


	return { two_num, five_num };
}


