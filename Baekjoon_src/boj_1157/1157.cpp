#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

char str[1000005] = { 0 };
int cnt[27] = { 0 };

int main() {

	scanf("%s", str);

	for (int i = 0; i < strlen(str); i++) {
		if ('A' <= str[i] && str[i] <= 'Z')
			cnt[str[i] - 'A']++;
		else if ('a' <= str[i] && str[i] <= 'z')
			cnt[str[i] - 'a']++;
	}

	int max_v = -1, idx = -1;

	for (int i = 0; i < 27; i++) {
		if (max_v < cnt[i]) {
			max_v = cnt[i];
			idx = i;
		}
	}

	int flag = 0;

	for (int i = 0; i < 27; i++) {
		if (max_v == cnt[i])
			flag++;
	}

	if (flag >= 2)
		printf("?\n");
	else
		printf("%c", (char)idx + 'A');

	return 0;
}
