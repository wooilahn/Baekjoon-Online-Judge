#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  while(true){
    getline(cin, s);

	if(s.size() == 0)
	  break;

    int n_lower = 0;
    int n_upper = 0;
    int n_digit = 0;
    int n_space = 0;

    for(int i=0; i<s.size(); i++){
      if(islower(s[i]))
	    n_lower++;
	  else if(isupper(s[i]))
	    n_upper++;
	  else if(isdigit(s[i]))
	    n_digit++;
	  else if(isspace(s[i]))
	    n_space++;
    }

    printf("%d %d %d %d\n", n_lower, n_upper, n_digit, n_space);
  }

  return 0;
}

