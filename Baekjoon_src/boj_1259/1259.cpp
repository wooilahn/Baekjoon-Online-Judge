#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	char str[10] = { 0 };
	int len;

	while (true) {
		bool check = true;
		scanf("%s", str);
		len = strlen(str);

		if (!strcmp(str, "0"))
			break;

		for (int i = 0; i < len / 2; i++) {
			if (str[i] != str[len - 1 - i]) {
				check = false;
				break;
			}
		}

		if (check)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
