#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  for(int i=0; i<s.length()-1; i++){
    if(i == 0)
	  cout << char(s[i]);
	else if(s[i] == '-')
	  cout << char(s[i+1]);
  }
  cout << endl;

  return 0;
}
