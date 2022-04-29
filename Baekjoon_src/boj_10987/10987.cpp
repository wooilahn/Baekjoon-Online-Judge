#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int cnt = 0;

  for(int i=0; i<s.size(); i++){
    char tar = char(s.at(i));
	if(tar == 'a' || tar == 'e' || tar == 'i' || tar == 'o' || tar == 'u')
	  cnt++;
  }

  cout << cnt << endl;

  return 0;
}
