#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

long long dp[70] = {0};

int main(){
  int t;
  scanf("%d", &t);

  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for(int i=4; i<=67; i++){
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
  }

  while(t--){
    int k;
	scanf("%d", &k);
	printf("%lld\n", dp[k]);
  }

 return 0;
}
