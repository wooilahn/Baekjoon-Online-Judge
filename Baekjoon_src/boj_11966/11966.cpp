#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
typedef long long ll;

int main() {
	ll N;
	scanf("%lld", &N);

	ll a = 1;
	bool flag = false;
	
	for (int i = 1; i <= 31; i++) {
		if (a == N) {
			flag = true;
			break;
		}

		a *= 2;		
	}

	if (flag)
		printf("1\n");
	else
		printf("0\n");

	return 0;
}
