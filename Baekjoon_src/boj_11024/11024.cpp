#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  string s;
  getline(cin, s);

  while(T--){
	getline(cin, s);
	stringstream sstream(s);
	string token;
	int ans = 0;

	while(getline(sstream, token, ' ' )){
	  ans += atoi(token.c_str());
	}

	cout << ans << endl;
  }

  return 0;
}
