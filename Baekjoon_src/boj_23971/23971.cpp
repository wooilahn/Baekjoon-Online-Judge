#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int H, W, N, M;
	scanf("%d %d %d %d", &H, &W, &N, &M);

	int Hp = (H / (N+1));
	if (H % (N+1))
		Hp++;

	int Wp = (W / (M+1));
	if (W % (M+1))
		Wp++;

	printf("%d\n", Hp * Wp);

	return 0;
}
