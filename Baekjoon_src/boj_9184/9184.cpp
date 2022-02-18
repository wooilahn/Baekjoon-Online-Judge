#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

long long dp[25][25][25] = {0};
bool check[25][25][25] = {0};

int main(){
  long long a, b, c;

  for(int i=0;i<=20;i++){
    dp[i][0][0] = 1;
	dp[0][i][0] = 1;
	dp[0][0][i] = 1;

	check[i][0][0] = true;
	check[0][i][0] = true;
	check[0][0][i] = true;
  }

  for(int i=0; i<=20; i++){
    for(int j=0; j<=20; j++){
	  dp[i][j][0] = 1;
	  dp[i][0][j] = 1;
	  dp[0][i][j] = 1;

	  check[i][j][0] = true;
	  check[i][0][j] = true;
	  check[0][i][j] = true;
	}
  }

  for(int i=0; i<=20; i++){
    for(int j=0; j<=20; j++){
	  for(int k=0; k<=20; k++){
	    if(check[i][j][k] == true)
		  continue;

	    if(i<j && j<k)
		  dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
		else
		  dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
	  }
	}
  }

  while(true){
    scanf("%lld %lld %lld", &a, &b, &c);

	if(a == -1 && b == -1 && c == -1)
	  return 0;

	printf("w(%d, %d, %d) = ", a, b, c);

	if(a<=0 || b<=0 || c<=0){
	  printf("%lld\n", 1);
	  continue;
	}
	if(a>20 || b>20 || c >20){
	  printf("%lld\n", dp[20][20][20]);
	  continue;
	}
	
	printf("%lld\n", dp[a][b][c]);
  }

  return 0;
}
