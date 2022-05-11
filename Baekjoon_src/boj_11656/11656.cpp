#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  vector<string> s_v;

  for(int i=0; i<s.size(); i++)
    s_v.push_back(s.substr(i));

  sort(s_v.begin(), s_v.end());

  for(int i=0; i<s_v.size(); i++)
    cout << s_v[i] << endl;

  return 0;
}
