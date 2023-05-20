#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
	long long a, b, c, d;

	while (true) {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

		if (a + b + c + d == 0)
			break;

		int cnt = 0;
		while (true) {
			long long target = (a + b + c + d) / 4;

			if (target == a && target == b && target == c && target == d) {
				printf("%d\n", cnt);
				break;
			}

			cnt++;
			long long t_a, t_b, t_c, t_d;

			t_a = abs(a - b);
			t_b = abs(b - c);
			t_c = abs(c - d);
			t_d = abs(d - a);
			
			a = t_a;
			b = t_b;
			c = t_c;
			d = t_d;
		}
	}
	
	return 0;
}
