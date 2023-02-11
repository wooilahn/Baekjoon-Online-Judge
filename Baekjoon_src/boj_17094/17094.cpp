#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int len;
  cin >> len;

  string s;
  cin >> s;

  int tcnt = 0;
  int ecnt = 0;

  for(int i=0; i<s.size(); i++){
    if(s[i] == '2')
	  tcnt++;
	else if(s[i] == 'e')
	  ecnt++;
  }

  if(tcnt > ecnt)
    cout << "2\n";
  else if(tcnt < ecnt)
    cout << "e\n";
  else if(tcnt == ecnt)
    cout << "yee\n";

  return 0;
}
