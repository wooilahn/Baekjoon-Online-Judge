#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

using namespace std;
bool check[1005] = { 0 };

void check_aberration();

int main() {

	int N, ans = 0;
	scanf("%d", &N);

	check_aberration();

	for (int i = 1; i <= N; i++) {
		if (check[i])
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}

void check_aberration() {
	for (int i = 1; i <= 1000; i++) {
		int target = i;

		bool flag = true;
		int cur_v = target % 10, next_v = 0, diff = -100;
		target /= 10;

		if (target == 0) {
			check[i]++;
			continue;
		}
		
		while (target != 0) {
			next_v = target % 10;
			target /= 10;
			
			if (diff == -100) {
				diff = cur_v - next_v;
				cur_v = next_v;
			}
			else {

				if (diff == cur_v - next_v) {
					cur_v = next_v;
					continue;
				}
				else {
					flag = false;
					break;
				}
			}
		}

		if (flag) 
			check[i] = true;
		
	}
}
