#include <iostream>
#include <vector>

using namespace std;

int dp[1005] = {0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int idx = 1;

  for(int i=1; i<= 1000; i++){
    for(int k=1; k<=i; k++){
	  if (idx > 1000)
	    break;

	  dp[idx] = dp[idx-1] + i;
	  idx++;
	}
  }

  int A, B;
  cin >> A >> B;
  cout << dp[B] - dp[A-1] << '\n';

  return 0;
}

