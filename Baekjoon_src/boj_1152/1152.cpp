#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

char str[1000005] = { 0 };
int ans = 0;

int main() {
	fgets(str, sizeof(str), stdin);

	for (int i = strlen(str)-1; i >= 0; i--) {
		if (str[i] == '\n' || str[i] == EOF) {
			str[i] = 0;
			break;
		}
	}

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') 
			ans++;
	}

	if (str[0] == ' ')
		ans--;

	if (str[strlen(str) - 1] == ' ') {

		ans--;
	}

	printf("%d\n", ans + 1);

	return 0;
}
