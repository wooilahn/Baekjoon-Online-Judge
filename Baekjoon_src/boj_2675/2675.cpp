#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		char S[21] = { 0 };
		int R;

		scanf("%d %s", &R, S);

		for (int i = 0; i < strlen(S); i++) {
			for (int j = 0; j < R; j++)
				printf("%c", S[i]);
		}

		printf("\n");
	}

	return 0;
}
