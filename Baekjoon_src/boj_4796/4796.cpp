#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	long long L, P, V;
	int t = 1;
	
	for(;;t++) {
		scanf("%lld %lld %lld", &L, &P, &V);

		if (L == 0 && P == 0 && V == 0)
			break;

		long long ans = 0;

		if (V % P < L)
			ans = (V/P)*L + (V%P);
		else if(V % P >= L)
			ans = (V/P)*L + L;

		printf("Case %d: %lld\n", t, ans);
	}

	return 0;
}
