#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  string s1, s2;

  cin >> s1;
  cin >> s2;

  string ch_s1;

  for(int i=0; i<s1.size(); i++){
    if( (s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z') )
	  ch_s1.push_back(s1[i]);
  }

  if(ch_s1.find(s2) != string::npos)
    cout << '1' << '\n';
  else
    cout << '0' << '\n';

  return 0;
}
