#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  string fan =	":fan:";
  s = ':' + s + ':';

  cout << fan << fan << fan << '\n';
  cout << fan << s << fan << '\n';
  cout << fan << fan << fan << '\n';

  return 0;
}
