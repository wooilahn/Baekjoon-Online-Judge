#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  while(true){
    cin >> s;

	if(s[0] == '#')
	  break;

	int n_one = 0;
	int n_zero = 0;

	for(int i=0; i<s.size(); i++){
	  if(s[i] == '0')
	    n_zero++;
	  else if(s[i] == '1')
	    n_one++;
	}

	if(s[s.size()-1] == 'e'){ // even
	  if(n_one % 2 == 0)
	    s[s.size()-1] = '0';
	  else
	    s[s.size()-1] = '1';
	}
	else if(s[s.size()-1] == 'o'){ // odd
	  if(n_one % 2 == 0)
	    s[s.size()-1] = '1';
	  else
	    s[s.size()-1] = '0';
	}

	cout << s << endl;
  }

  return 0;
}

