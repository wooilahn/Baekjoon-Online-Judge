#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  string s;
  string ans;

  int l;
  int min_level = 5;

  while(N--){
    cin >> s >> l;

	if(min_level > l){
	  min_level = l;
	  ans = s;
	}
  }

  cout << ans << endl;
  return 0;
}
