#include <iostream>
#include <algorithm>

using namespace std;
int slope[1005] = {0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  for(int i=0; i<N; i++)
    cin >> slope[i];

  int ans = 0;
  int cur_slope = 0;

  for(int i=0; i<N-1; i++){
    if(slope[i] < slope[i+1])
	  cur_slope += (slope[i+1] - slope[i]);
	else{
	  ans = max(cur_slope, ans);
	  cur_slope = 0;
	}
  }

  ans = max(cur_slope, ans);

  cout << ans << '\n';

  return 0;
}
