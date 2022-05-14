#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;

  while(true){
	  getline(cin, s);

	  if(s.compare("EOI") == 0)
	    break;

	  for (int i = 0; i < s.size(); i++) {
		  if (isupper(s[i]))
			  s[i] = tolower(s[i]);
	  }

	  if (s.find("nemo") == -1)
		  cout << "Missing" << endl;
	  else
	      cout << "Found" << endl;
  }

  return 0;
}
