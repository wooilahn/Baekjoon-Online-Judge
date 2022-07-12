#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  int N, K;
  int num, ans = 0;

  while(T--){
    cin >> N >> K;
	ans = 0;
	
	while(N--){
	 cin >> num;
	 ans += num / K;
	}
	
	cout << ans << endl;
  }

  return 0;
}
