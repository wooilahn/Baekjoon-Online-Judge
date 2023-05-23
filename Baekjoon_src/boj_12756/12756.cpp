#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {

	int a_attack, a_life;
	int b_attack, b_life;

	scanf("%d %d %d %d", &a_attack, &a_life, &b_attack, &b_life);


	while (true) {
		a_life -= b_attack;
		b_life -= a_attack;

		if (a_life <= 0 && b_life <= 0) {
			printf("DRAW");
			break;
		}
		else if (a_life > 0 && b_life <= 0) {
			printf("PLAYER A");
			break;
		}
		else if (a_life <= 0 && b_life > 0) {
			printf("PLAYER B");
			break;
		}
	}

	return 0;
}
