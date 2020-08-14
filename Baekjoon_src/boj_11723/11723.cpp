#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;
bool bit_mask[21] = { 0 };

int main() {
	int M;
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		char S[10] = { 0 };
		int n;
		scanf("%s", S);

		if (!strcmp(S, "add")) {
			scanf(" %d", &n);

			if (!bit_mask[n])
				bit_mask[n] = true;
			else if (bit_mask[n])
				continue;
		}
		else if (!strcmp(S, "remove")) {
			scanf(" %d", &n);
			if (bit_mask[n])
				bit_mask[n] = false;
			else if (!bit_mask[n])
				continue;
		}
		else if (!strcmp(S, "check")) {
			scanf(" %d", &n);
			printf("%d\n", bit_mask[n]);
		}
		else if (!strcmp(S, "toggle")) {
			scanf(" %d", &n);
			bit_mask[n] = !(bit_mask[n]);
		}
		else if (!strcmp(S, "all")) {
			for (int i = 1; i <= 20; i++)
				bit_mask[i] = true;
		}
		else if (!strcmp(S, "empty")) {
			for (int i = 1; i <= 20; i++)
				bit_mask[i] = false;
		}
	}

	return 0;
}
