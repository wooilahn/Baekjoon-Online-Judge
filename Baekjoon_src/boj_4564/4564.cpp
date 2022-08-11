#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  while(true){
    string s;
    cin >> s;
	
	if(s[0] == '0')
	  break;

	while(true){
	  cout << s;

	  if(s.size() == 1){
	    cout << '\n';
	    break;
	  }
	  else
	    cout << " ";

	  int sum = 1;
	  for(int k=0; k<s.size(); k++)
	    sum *= int(s[k]-'0');
	  
	  s = to_string(sum);
	}
  }

  return 0;
}
