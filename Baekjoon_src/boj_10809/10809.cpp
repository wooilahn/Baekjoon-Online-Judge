#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

using namespace std;

int alphabet[30] = { 0 };

int main() {

	char S[105] = { 0 };
	scanf("%s", S);

	for (int i = 0; i < 30; i++)
		alphabet[i] = -1;

	for (int i = 0; i < strlen(S); i++) {
		char c = S[i];

		if (alphabet[c - 'a'] >= 0)
			continue;
		else
			alphabet[c - 'a'] = i;
	}

	for (char i = 'a'; i <= 'z'; i++) 
		printf("%d ", alphabet[i - 'a']);
	
	printf("\n");

	return 0;
}
