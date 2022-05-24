#include <iostream>

using namespace std;
bool check[105] = {0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, num, ans = 0;
  cin >> N;

  for(int i=0; i<N; i++){
    cin >> num;

	if(check[num])
	  ans++;
	else
	  check[num] = true;
  }

  cout << ans << endl;

  return 0;
}
