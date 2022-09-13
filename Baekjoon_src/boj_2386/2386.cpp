#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  while(true){
    getline(cin, s);

	if(s[0] == '#')
	  break;
	int cnt = 0;

	for(int i=2; i<s.size(); i++){
	  if(tolower(s[i]) == s[0])
	    cnt++;
	}
	cout << s[0] << ' ' << cnt << '\n';
  }

  return 0;
}

