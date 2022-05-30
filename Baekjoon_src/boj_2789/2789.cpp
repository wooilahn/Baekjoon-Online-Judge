#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
bool check[30] ={0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string tmp_s = "CAMBRIDGE";
  string s;
  cin >> s;

  for(int i=0; i<tmp_s.size(); i++){
    if(check[tmp_s[i]-'A'] == false)
	  check[tmp_s[i]-'A'] = true;
  }

  for(int i=0; i<s.size(); i++){
    if(check[s[i]-'A'] == false)
	  cout << s[i];
  }
  cout << endl;

  return 0;
}
