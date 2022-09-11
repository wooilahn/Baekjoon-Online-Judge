#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  string s;

  while(true){
    int sum = 0;
	int oct = 1;
    cin >> s;

	if(s[0] == '#')
	  break;

	for(int i=s.size()-1; i>=0; i--){
	  if(s[i] == '\\')
	    sum += oct;
	  else if(s[i] == '(')
	    sum += 2*oct;
	  else if(s[i] == '@')
	    sum += 3*oct;
	  else if(s[i] == '?')
	    sum += 4*oct;
	  else if(s[i] == '>')
	    sum += 5*oct;
	  else if(s[i] == '&')
	    sum += 6*oct;
	  else if(s[i] == '%')
	    sum += 7*oct;
	  else if(s[i] == '/')
	    sum += -1*oct;

	  oct *= 8;
	}

	cout << sum << '\n';
  }

  return 0;
}
