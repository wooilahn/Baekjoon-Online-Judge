#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

int N, K, ans = 0;
bool alphabets[27] = { 0 };
char words[51][17] = { 0 };

void func(int cur, int cnt);

int main() {

	scanf("%d %d", &N, &K);

	for (int i = 0;i < N;i++)
		scanf("%s", words[i]);

	if (K < 5) {
		printf("0\n");
		return 0;
	}

	K -= 5;
	alphabets['a' - 'a'] = true;
	alphabets['c' - 'a'] = true;
	alphabets['i' - 'a'] = true;
	alphabets['n' - 'a'] = true;
	alphabets['t' - 'a'] = true;

	func(0, 0);
	printf("%d\n", ans);

	return 0;
}

void func(int cur, int cnt) {

	if (cnt == K) {
		int tmp = 0;

		for (int i = 0;i < N;i++) {
			
			bool flag = true;

			for (int s = 0;s < strlen(words[i]);s++) {
				if (alphabets[words[i][s] - 'a'] == false) {
					flag = false;
					break;
				}
			}

			if (flag)
				tmp++;
		}

		if (tmp > ans) 
			ans = tmp;
		
		
		return;
	}

	for (int i = cur;i < 27;i++) {
		if (alphabets[i])
			continue;

		alphabets[i] = true;
		func(i + 1, cnt + 1);
		alphabets[i] = false;
	}

	return;
}
