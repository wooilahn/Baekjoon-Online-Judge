#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  string s;
  while(T--){
    cin >> s;
	cout << s[0] << s[s.length()-1] << endl;
  }
  return 0;
}
