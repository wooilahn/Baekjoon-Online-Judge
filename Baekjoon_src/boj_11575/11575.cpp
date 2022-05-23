#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T, a, b;
  string s;

  cin >> T;

  while(T--){
    cin >> a >> b;
	cin >> s;

	for(int i=0; i<s.size(); i++){
	  int ex = (a*(s[i]-'A') + b) % 26;
	  s[i] = char('A' + ex);
	}

	cout << s << endl;
  }

  return 0;
}
