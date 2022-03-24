#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;
int t_arr[1500003] = {0};
int p_arr[1500003] = {0};
int dp[1500003] = {0};
int ans = 0;

int main(){
  int N;
  scanf("%d", &N);

  for(int i=1; i<=N; i++)
    scanf("%d %d", &t_arr[i], &p_arr[i]);
  
  for(int k=N; k>=1; k--){
    int target_day = k + t_arr[k] - 1;

	if(target_day > N){
	  dp[k] = dp[k+1];
	  continue;
	}

	dp[k] = max(dp[k+1], p_arr[k] + dp[target_day + 1]);
  }

  printf("%d\n", dp[1]);

  return 0;
}
