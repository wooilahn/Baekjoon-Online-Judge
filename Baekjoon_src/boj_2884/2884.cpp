#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int H, M;
	scanf("%d %d", &H, &M);

	if (M >= 45) 
		printf("%d %d\n", H, M - 45);
	else if (H == 0) 
		printf("%d %d\n", 23, 60 - (45 - M));
	else 
		printf("%d %d\n", H-1, 60 - (45 - M));
	
	return 0;
}
