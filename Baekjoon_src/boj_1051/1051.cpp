#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int map[55][55] = { 0 };

bool is_square(int i, int j, int k) {
	return (map[i][j] == map[i + k][j] && map[i][j] == map[i][j + k] && map[i][j] == map[i + k][j + k]);
}

int main() {

	int N, M, ans = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0;i < N;i++) 
		for (int j = 0;j < M;j++) 
			scanf("%1d", &map[i][j]);

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			for (int k = 1; i+k<N && j+k<M; k++) {
				if (is_square(i, j, k) && ans < k)
					ans = k;
			}
		}
	}

	printf("%d\n", (ans+1)*(ans+1));

	return 0;
}
