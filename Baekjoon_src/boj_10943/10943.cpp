#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand((unsigned int)time(NULL));
	printf("%d\n", (rand() % 10) + 1);
	return 0;
}
