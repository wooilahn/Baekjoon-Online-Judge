#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int sd_burger, jd_burger, hd_burger;
	int coke, soda;
	int burger, beverage;

	scanf("%d %d %d %d %d", &sd_burger, &jd_burger, &hd_burger, &coke, &soda);

	burger = min(sd_burger, min(jd_burger, hd_burger));
	beverage = min(coke, soda);

	printf("%d\n", burger + beverage - 50);
	return 0;
}
