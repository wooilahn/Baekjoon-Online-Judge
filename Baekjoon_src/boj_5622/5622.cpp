#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

char str[16] = { 0 };

int main() {

	int sum = 0;
	scanf("%s", str);

	for (int i = 0;i < strlen(str);i++) {
		if ('A' <= str[i] && str[i] <= 'C')
			sum += 3;
		else if ('D' <= str[i] && str[i] <= 'F')
			sum += 4;
		else if ('G' <= str[i] && str[i] <= 'I')
			sum += 5;
		else if ('J' <= str[i] && str[i] <= 'L')
			sum += 6;
		else if ('M' <= str[i] && str[i] <= 'O')
			sum += 7;
		else if ('P' <= str[i] && str[i] <= 'S')
			sum += 8;
		else if ('T' <= str[i] && str[i] <= 'V')
			sum += 9;
		else if ('W' <= str[i] && str[i] <= 'Z')
			sum += 10;
	}

	printf("%d\n", sum);

	return 0;
}
