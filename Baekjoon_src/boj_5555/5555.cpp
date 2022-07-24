#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  int N;
  int ans = 0;

  cin >> s;
  cin >> N;

  string s2;
  while(N--){
    cin >> s2;
	s2 = s2+s2;

	if(s2.find(s) != -1){
	  ans++;
	}
  }

  cout << ans << '\n';
  
  return 0;
}
