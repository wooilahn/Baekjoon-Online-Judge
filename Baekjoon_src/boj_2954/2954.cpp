#include <iostream>
#include <string>

using namespace std;

bool is_vowel(char c){
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return true;
  else
    return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  string ans;
  getline(cin, s);

  int idx = 0;

  while(true){
    if(idx == s.size())
	  break;

	ans.push_back(s[idx]);
	if(is_vowel(s[idx])){
	  idx += 3;
	}
	else
	  idx++;
  }

  cout << ans << endl;
  return 0;
}
