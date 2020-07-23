#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int n, criteria;
	scanf("%d", &n);

	criteria = n % 8;

	switch(criteria) {
	case 0:
		printf("2\n");
		break;
	case 1:
		printf("1\n");
		break;
	case 2:
		printf("2\n");
		break;
	case 3:
		printf("3\n");
		break;
	case 4:
		printf("4\n");
		break;
	case 5:
		printf("5\n");
		break;
	case 6:
		printf("4\n");
		break;
	case 7:
		printf("3\n");
		break;
	default:
		break;
	}

	return 0;
}
