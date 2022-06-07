#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  while(T--){
    string s;
	cin >> s;

	for(int i=0; i<s.size(); i++){
	  if(islower(s[i]) == 0)
	   s[i] = tolower(s[i]);
	}
	cout << s << endl;
  }

  return 0;
}
