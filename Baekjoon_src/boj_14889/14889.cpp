#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <vector>

using namespace std;

int N = 0, ans = INT_MAX;
int stats[22][22] = { 0 };
int t1_arr[15] = {  0 };

void dfs(int cnt, int pos);

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &stats[i][j]);
		}
	}

	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}

void dfs(int cnt, int pos) {

	if (cnt == N / 2) {
		bool chk_arr[22] = { 0 };

		int team1 = 0, team2 = 0, dif;
		vector<int> t2_arr;

		for (int i = 0; i < N / 2; i++) 
			chk_arr[t1_arr[i]] = true;
		
		for (int i = 0; i < N; i++) 
			if (chk_arr[i] == false)
				t2_arr.push_back(i);

		for (int i = 0; i < N / 2; i++) {
			for (int j = i+1; j < N / 2; j++) {
				team1 += (stats[t1_arr[i]][t1_arr[j]] + stats[t1_arr[j]][t1_arr[i]]);
				team2 += (stats[t2_arr[i]][t2_arr[j]] + stats[t2_arr[j]][t2_arr[i]]);
			}
		}

		dif = abs(team1 - team2);

		if (dif < ans) 
			ans = dif;
		
	}

	for (int i = pos; i < N; i++) {
		t1_arr[cnt] = i;
		dfs(cnt + 1, i + 1);
		t1_arr[cnt] = 0;
	}

	return;
}
