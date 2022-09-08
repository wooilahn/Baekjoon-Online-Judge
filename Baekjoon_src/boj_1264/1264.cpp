#include <iostream>
#include <string>

using namespace std;

bool judge_moum(char c){
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return true;
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;

  while(true){
    getline(cin, s);
	int cnt = 0;

    if(s[0] == '#')
	  break;

	for(int i=0; i<s.size(); i++){
	  if(judge_moum(tolower(s[i])))
	    cnt++;
	}

	cout << cnt << '\n';
  }

 return 0;
}
 
