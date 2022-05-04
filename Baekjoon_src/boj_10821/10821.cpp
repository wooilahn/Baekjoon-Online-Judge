#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int ans = 0;
  string s;
  cin >> s;

  for(int i=0; i<s.size(); i++)
    if(s[i] == ',')
	  ans++;
  ans++;
  cout << ans << endl;

  return 0;
}
