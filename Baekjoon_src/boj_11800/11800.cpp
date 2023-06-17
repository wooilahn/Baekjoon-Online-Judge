#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	int a, b;
	for(int i=1; i<=T; i++) {
		scanf("%d %d", &a, &b);
		printf("Case %d: ", i);

		int max_v = max(a, b);
		int min_v = min(a, b);

		if (max_v == min_v) {
			switch (max_v) {
			case 1:
				printf("Habb Yakk\n");
				break;
			case 2:
				printf("Dobara\n");
				break;
			case 3:
				printf("Dousa\n");
				break;
			case 4:
				printf("Dorgy\n");
				break;
			case 5:
				printf("Dabash\n");
				break;
			case 6:
				printf("Dosh\n");
				break;
			default: 
				break;
			}
		}
		else {
			if (max_v == 6 && min_v == 5) {
				printf("Sheesh Beesh\n");
				continue;
			}

			switch (max_v) {
			case 1:
				printf("Yakk ");
				break;
			case 2:
				printf("Doh ");
				break;
			case 3:
				printf("Seh ");
				break;
			case 4:
				printf("Ghar ");
				break;
			case 5:
				printf("Bang ");
				break;
			case 6:
				printf("Sheesh ");
				break;
			default:
				break;
			}

			switch (min_v) {
			case 1:
				printf("Yakk\n");
				break;
			case 2:
				printf("Doh\n");
				break;
			case 3:
				printf("Seh\n");
				break;
			case 4:
				printf("Ghar\n");
				break;
			case 5:
				printf("Bang\n");
				break;
			case 6:
				printf("Sheesh\n");
				break;
			default:
				break;
			}
		}
	}

	return 0;
}
