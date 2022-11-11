#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  for(int i=0; i<s.size(); i++){
    cout << char(toupper(s[i]));
  }
  cout << '\n';

  return 0;
}
