#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;
double scores[1002] = { 0 };

int main() {
	char str[82] = { 0 };
	int T;
	scanf("%d", &T);

	while (T--) {
		int ans = 0, succ = 0;
		scanf("%s", str);

		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == 'O') {
				ans += (succ + 1);
				succ++;
			}
			else if (str[i] == 'X')
				succ = 0;
		}

		printf("%d\n", ans);
	}

	return 0;
}
