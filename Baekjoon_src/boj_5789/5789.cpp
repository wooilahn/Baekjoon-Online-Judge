#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  string s;
  while(N--){
    cin >> s;

	if(s[s.size()/2] == s[s.size()/2 - 1])
	  cout << "Do-it" << endl;
	else
	  cout << "Do-it-Not" << endl;
  }

  return 0;
}
