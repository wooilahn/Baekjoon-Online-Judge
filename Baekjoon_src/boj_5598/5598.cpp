#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  for(int i=0; i<s.size(); i++){
    int idx = (int)s[i] - 'A' - 3;
	
	if(idx < 0)
	  idx = 'Z'-'A'+idx+1;

	s[i] = (char)('A' + idx);
  }

  cout << s << endl;
  return 0;
}
