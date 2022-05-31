#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  string s;

  cin >> N;
  getline(cin, s);

  for(int i=1; i<=N; i++){
    getline(cin, s);
	cout << i << ". " << s << endl;
  }

  return 0;
}
