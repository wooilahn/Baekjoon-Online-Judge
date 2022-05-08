#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  getline(cin, s);

  for(int i=0; i<s.size(); i++){
	if(isupper(s[i])){
	  int idx = (s[i]-'A'+13) % 26;
	  s[i] = char('A' + idx);
	}
	else if(islower(s[i])){
	  int idx = (s[i]-'a'+13) % 26;
	  s[i] = char('a' + idx);
	}
  }

  cout << s << endl;
  return 0;
}
