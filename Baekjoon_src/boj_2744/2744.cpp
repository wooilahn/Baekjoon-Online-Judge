#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  for(int i=0; i<s.length(); i++){
    if(islower(s[i]))
	  cout << char('A' + (s[i]-'a'));
	else if(isupper(s[i]))
	  cout << char('a' + (s[i]-'A'));
  }
  cout << endl;

  return 0;
}
