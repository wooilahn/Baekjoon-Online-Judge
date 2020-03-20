#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
int dp[2005][2005] = { 0 };
int arr[2005] = { 0 };
int N, M, S, E;

void solve();

int main() {

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	solve();

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &S, &E);
		printf("%d\n", dp[S][E]);
	}

	return 0;
}

void solve() {

	// initialize the DP table
	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;

		if (i + 1 <= N) 
			dp[i][i + 1] = (int)(arr[i] == arr[i + 1]);
		
		if (i + 2 <= N) 
			dp[i][i + 2] = (int)(arr[i] == arr[i + 2]);
		
	}
	
	// make the DP table
	for (int i = 3; i <= N; i++) {
		for (int j = 1; j+i <= N; j++) 
				dp[j][j + i] = (int)(dp[j + 1][j + i - 1] && (arr[j] == arr[j + i]));
	}

	return;
}
