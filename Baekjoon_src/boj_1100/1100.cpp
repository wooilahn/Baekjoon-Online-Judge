#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

char map[10][10] = { 0 };

int main() {

	int ans = 0;

	for (int i = 0;i < 8;i++) 
		scanf("%s", map[i]);
	
	for (int i = 0;i < 8;i++) {
		if (i % 2 == 0) {
			if (map[i][0] == 'F')
				ans++;
			if (map[i][2] == 'F')
				ans++;
			if (map[i][4] == 'F')
				ans++;
			if (map[i][6] == 'F')
				ans++;
		}
		else if (i % 2 == 1) {
			if (map[i][1] == 'F')
				ans++;
			if (map[i][3] == 'F')
				ans++;
			if (map[i][5] == 'F')
				ans++;
			if (map[i][7] == 'F')
				ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
}
