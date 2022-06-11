#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  getline(cin, s);
  stringstream sstream(s);
  string token;

  int sum = 0;

  while(getline(sstream, token, ' '))
    sum += atoi(token.c_str());

  cout << sum << endl;

  return 0;
}
