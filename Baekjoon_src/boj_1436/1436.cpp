#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {

	int N;
	int cnt = 0;
	char str[100] = { 0 };
	scanf("%d", &N);

	for (long long i = 666;; i++) {
		long long tmp = i;
		memset(str, 0, sizeof(str));
		sprintf(str, "%lld", tmp);

		int len = strlen(str);
		int t_cnt = 0;
		char bef, aft;

		bef = str[0];
		if (bef == '6')
			t_cnt++;

		for (int k = 1; k < len; k++) {
			aft = str[k];

			if (bef != '6' && aft == '6')
				t_cnt++;
			else if (bef == '6' && aft == '6') 
				t_cnt++;
			else 
				t_cnt = 0;
			
			if (t_cnt == 3) {
				cnt++;
				break;
			}

			bef = aft;
		}

		if (N == cnt) {
			printf("%lld\n", i);
			break;
		}
	}

	return 0;
}
