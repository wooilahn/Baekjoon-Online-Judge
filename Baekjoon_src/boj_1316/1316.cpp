#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

int check[27] = { 0 };
char str[105] = { 0 };

int main() {
	int N, ans = 0;
	scanf("%d", &N);

	for (int i = 0;i < N;i++) {
		bool flag = true;
		memset(check, 0, sizeof(check));
		memset(str, 0, sizeof(str));
		scanf("%s", str);

		for (int k = 0;k < strlen(str);k++) {
			check[str[k] - 'a']++;

			while (str[k] == str[k + 1])
				k++;
		}

		for (int k = 0;k < 27;k++) {
			if (check[k] > 1) {
				flag = false;
				break;
			}
		}

		if (flag)
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}
