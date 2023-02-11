#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  string s;

  cin >> N;

  while(N--){
    cin >> s;

	if(s.size() >= 6 && s.size() <= 9)
	  cout << "yes\n";
	else
	  cout << "no\n";
  }

  return 0;
}
