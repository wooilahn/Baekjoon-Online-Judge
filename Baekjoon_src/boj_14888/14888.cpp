#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits>
#include <limits.h>

using namespace std;

int N, max = -1111111111, min = INT_MAX;
int A[105] = { 0 };
int O[105] = { 0 };
int oper[4] = { 0 };

void dfs(int cnt, int add, int sub, int mul, int div);

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) 
		scanf("%d", &A[i]);

	for (int i = 0; i < 4; i++) 
		scanf("%d", &oper[i]);
	
	dfs(0, 0, 0, 0, 0);
	printf("%d\n%d\n", max, min);

	return 0;
}

void dfs(int cnt, int add, int sub, int mul, int div) {
	if (cnt == N - 1) {

		int tmp = A[0];

		for (int i = 1; i < N; i++) {
			if (O[i - 1] == 1)  // add (+)
				tmp = tmp + A[i];
			else if (O[i - 1] == 2)  // sub (-)
				tmp = tmp - A[i];
			else if (O[i - 1] == 3)  // mul (*)
				tmp = tmp * A[i];
			else if (O[i - 1] == 4)  // div (/)
				tmp = tmp / A[i];
		 }

		if (max < tmp) {
			max = tmp;
		}
		if (min > tmp) {
			min = tmp;
		}

		return;
	}

	if (add < oper[0]) {
		O[cnt] = 1; // add
		dfs(cnt + 1, add + 1, sub, mul, div);
	}
	if (sub < oper[1]) {
		O[cnt] = 2;
		dfs(cnt + 1, add, sub + 1, mul, div);
	}
	if (mul < oper[2]) {
		O[cnt] = 3;
		dfs(cnt + 1, add, sub, mul + 1, div);
	}
	if (div < oper[3]) {
		O[cnt] = 4;
		dfs(cnt + 1, add, sub, mul, div + 1);
	}

	return;
}
